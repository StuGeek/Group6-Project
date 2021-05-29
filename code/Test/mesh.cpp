#include <math.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <vector>

/*
代码中没用到这三个宏，后期如果有需要可以加进去
#define N_STATEVAR 4 // value的状态数
#define MESH_DIM 2 // Mesh的维度
#define N_NODESPERCELL 4 // 一个cell包含节点的数量
*/

typedef double real;

class Mesh {
   private:
    int node_num, cell_num, edge_num, bedge_num;

    std::vector<std::vector<double>> nodes;
    std::vector<std::vector<int>> cells;
    std::vector<std::vector<int>> edges;
    std::vector<std::vector<int>> ecells;
    std::vector<std::vector<int>> bedges;
    std::vector<int> bcells;
    std::vector<int> bounds;

    std::vector<int> cell2edge;
    std::vector<int> edge2color;
    std::vector<std::vector<int>> color2edge;

    std::vector<std::vector<double>> values;

   public:
    Mesh();
    bool loadFromDat(FILE* fp, char* pathname);
    void shader();  // 着色器
    void kernel();

    static double convert2BinaryDouble(double d);
    static float convert2BinaryFloat(float f);
    static int convert2BinaryInt(int d);

    bool writeToVTKAscii(FILE* fp);
    bool writeToVTKBinary(FILE* fp);
};

Mesh::Mesh() {
    node_num = cell_num = edge_num = bedge_num = 0;
}

// 从Dat文件中加载一个Mesh
bool Mesh::loadFromDat(FILE* fp, char* filename) {
    // 打开文件
    if ((fp = fopen(strcat("./",  filename), "r")) == nullptr) {
        printf("can't open file %s\n", filename);
        return false;
    }

    // 读取参数
    if (fscanf(fp, "%d %d %d %d \n", &node_num, &cell_num, &edge_num, &bedge_num) != 4) {
        printf("error reading nums from %s\n", filename);
        return false;
    }

    cell2edge.resize(4 * cell_num, -1);
    edge2color.resize(4 * edge_num, -1);

    // 读取顶点，一个顶点有x，y两个维度
    double x, y;
    for (int n = 0; n < node_num; n++) {
        if (fscanf(fp, "%lf %lf \n", &x, &y) != 2) {
            printf("error reading nodes from %s\n", filename);
            return false;
        }
        nodes.push_back(std::vector<double>{x, y});
    }

    // 读取单元cell， 一个cell通过其四个顶点确定
    int v1, v2, v3, v4;
    for (int n = 0; n < cell_num; n++) {
        if (fscanf(fp, "%d %d %d %d \n", &v1, &v2, &v3, &v4) != 4) {
            printf("error reading cells from %s\n", filename);
            return false;
        }
        cells.push_back(std::vector<int>{v1, v2, v3, v4});
    }

    // 读取边，一条边由两个顶点和与该边邻接的两个单元确定
    int e1, e2, ec1, ec2;
    for (int n = 0; n < edge_num; n++) {
        if (fscanf(fp, "%d %d %d %d \n", &e1, &e2, &ec1, &ec2) != 4) {
            printf("error reading edges from %s\n", filename);
            return false;
        }
        edges.push_back(std::vector<int>{e1, e2});
        ecells.push_back(std::vector<int>{ec1, ec1});
    }

    // 读取位于边界的边，一条位于边界的边由其两个顶点，与该边邻接的一个单元和一个边界标识符bound确定
    int b;
    for (int n = 0; n < bedge_num; n++) {
        if (fscanf(fp, "%d %d %d %d \n", &v1, &v2, &ec1, &b) != 4) {
            printf("error reading bound edges from %s\n", filename);
            return false;
        }
        bedges.push_back(std::vector<int>{v1, v2});
        bcells.push_back(ec1);
        bounds.push_back(b);
    }

    // 初始化cell2edge，每个单元格对应的边
    cell2edge.resize(cell_num);
    for (int n = 0; n < edge_num; n++) {
        cell2edge[ecells[n][0]].push_back(n);
        cell2edge[ecells[n][1]].push_back(n);
    }

    return true;
}

// 给每条边赋一个color值，要求与这条边邻接的两个单元格的其他边的值不一样
void Mesh::shader() {
    // 所有边的color先初始化为-1
    edge2color.resize(edge_num, -1);

    int color;
    bool vaild;
    std::vector<int> cedges_1, cedges_2;

    for (int i = 0; i < edge_num; i++) {
        // 与一条边邻接的两个单元格的其他边
        cedges_1 = cell2edge[ecells[i][0]];
        cedges_2 = cell2edge[ecells[i][1]];

        color = 0;

        // 当前color与cedges_1和cedges_2中的边的color不一样时有效
        do {
            vaild = true;
            for (int n = 0; n < 4; n++) {
                if (edge2color[cedges_1[n]] == color || edge2color[cedges_2[n]] == color) {
                    vaild = false;
                    color++;
                    break;
                }
            }
        } while (!vaild);

        edge2color[i] = color;

        // 同时记录在color2edge中
        if (color2edge.size() == color) {
            color2edge.push_back(std::vector<int>{i});
        } else {
            color2edge[color].push_back(i);
        }
    }
}

// 没看懂源代码在干什么，变量名也相当鬼畜
void Mesh::kernel() {
    /*

    real gam, gm1, cfl, eps, mach, alpha, qinf[4];

    int    *becell, *ecell,  *bound, *bedge, *edge, *cell;
    real  *x, *q, *qold, *adt, *res;

    int    nnode,ncell,nedge,nbedge,niter;
    real  rms;

    double wall_t1, wall_t2;

    gam = 1.4f;
    gm1 = gam - 1.0f;
    cfl = 0.9f;
    eps = 0.05f;

    real mach  = 0.4f;
    real alpha = 3.0f*atan(1.0f)/45.0f;
    real p     = 1.0f;
    real r     = 1.0f;
    real u     = sqrt(gam*p/r)*mach;
    real e     = p/(r*gm1) + 0.5f*u*u;

    qinf[0] = r;
    qinf[1] = r*u;
    qinf[2] = 0.0f;
    qinf[3] = r*e;

    for(int n = 0; n < cell_num; n++){
        for(int m = 0; m < 4; m++){
            q[4 * n + m] = qinf[m];
            res[4 * n + m] = 0.0f;
        }
    }

    wall_t1 = omp_get_wtime();

    niter = 1000;
    double save = 0, area = 0, update = 0, flux_res = 0, perem = 0, wall_t_a = 0, wall_t_b = 0;

    #pragma omp parallel
    {
        for(int iter = 1; iter <= niter; iter++){

	        #pragma omp single
	        {
		        wall_t_b = omp_get_wtime();
	        }

	        #pragma omp for
            for (int i = 0; i < ncell; i++) {
                for (int n = 0; n < 4; n++)
                    qold[4 * i + n] = q[4 * i + n];
            }

	        #pragma omp single
            {
    	        wall_t_a = omp_get_wtime();
    	        save += wall_t_a - wall_t_b;
            }

            for(int k = 0; k < 2; k++){

                #pragma omp single
    	        {
    		        wall_t_b = omp_get_wtime();
    	        }

                #pragma omp for
                for (int i = 0; i < ncell; i++) {
                    double dx,dy, ri,u,v,c;

                    ri =  1.0f/q[4*i+0];
                    u  =   ri*q[4*i+1];
                    v  =   ri*q[4*i+2];
                    c  = sqrt(gam*gm1*(ri*q[4*i+3]-0.5f*(u*u+v*v)));

                    dx = x[cell[4*i+1]*2+0] - x[cell[4*i+0]*2+0];
                    dy = x[cell[4*i+1]*2+1] - x[cell[4*i+0]*2+1];
                    adt[i]  = fabs(u*dy-v*dx) + c*sqrt(dx*dx+dy*dy);

                    dx = x[cell[4*i+2]*2+0] - x[cell[4*i+1]*2+0];
                    dy = x[cell[4*i+2]*2+1] - x[cell[4*i+1]*2+1];
                    adt[i] += fabs(u*dy-v*dx) + c*sqrt(dx*dx+dy*dy);

                    dx = x[cell[4*i+3]*2+0] - x[cell[4*i+2]*2+0];
                    dy = x[cell[4*i+3]*2+1] - x[cell[4*i+2]*2+1];
                    adt[i] += fabs(u*dy-v*dx) + c*sqrt(dx*dx+dy*dy);

                    dx = x[cell[4*i+0]*2+0] - x[cell[4*i+3]*2+0];
                    dy = x[cell[4*i+0]*2+1] - x[cell[4*i+3]*2+1];
                    adt[i] += fabs(u*dy-v*dx) + c*sqrt(dx*dx+dy*dy);

                    adt[i] = adt[i] / cfl;
                }

	            #pragma omp single
                {
                    wall_t_a = omp_get_wtime();
                    area += (wall_t_a - wall_t_b);
                    // calculate flux residual
                    wall_t_b = omp_get_wtime();
                }

                for(size_t color = 0; color < color2edge.size(); ++color){
    	            #pragma omp for
    	            for(size_t ind = 0; ind < color2edge[color].size(); ++ind){
    		            int i = color2edge[color][ind];
    		            double dx,dy,mu, ri, p1,vol1, p2,vol2, f;

    		            dx = x[edge[2*i+0]*2+0] - x[edge[2*i+1]*2+0];
        	            dy = x[edge[2*i+0]*2+1] - x[edge[2*i+1]*2+1];

        	            ri   = 1.0f/q[ecell[2*i+0]*4+0];
        	            p1   = gm1*(q[ecell[2*i+0]*4+3]-0.5f*ri*(q[ecell[2*i+0]*4+1]*q[ecell[2*i+0]*4+1]+q[ecell[2*i+0]*4+2]*q[ecell[2*i+0]*4+2]));
        	            vol1 =  ri*(q[ecell[2*i+0]*4+1]*dy - q[ecell[2*i+0]*4+2]*dx);

        	            ri   = 1.0f/q[ecell[2*i+1]*4+0];
        	            p2   = gm1*(q[ecell[2*i+1]*4+3]-0.5f*ri*(q[ecell[2*i+1]*4+1]*q[ecell[2*i+1]*4+1]+q[ecell[2*i+1]*4+2]*q[ecell[2*i+1]*4+2]));
        	            vol2 =  ri*(q[ecell[2*i+1]*4+1]*dy - q[ecell[2*i+1]*4+2]*dx);

        	            mu = 0.5f*(adt[ecell[2*i+0]]+adt[ecell[2*i+1]])*eps;

        	            f = 0.5f*(vol1* q[ecell[2*i+0]*4+0]         + vol2* q[ecell[2*i+1]*4+0]        ) + mu*(q[ecell[2*i+0]*4+0]-q[ecell[2*i+1]*4+0]);
        	            res[ecell[2*i+0]*4+0] += f;
        	            res[ecell[2*i+1]*4+0] -= f;
        	            f = 0.5f*(vol1* q[ecell[2*i+0]*4+1] + p1*dy + vol2* q[ecell[2*i+1]*4+1] + p2*dy) + mu*(q[ecell[2*i+0]*4+1]-q[ecell[2*i+1]*4+1]);
        	            res[ecell[2*i+0]*4+1] += f;
        	            res[ecell[2*i+1]*4+1] -= f;
        	            f = 0.5f*(vol1* q[ecell[2*i+0]*4+2] - p1*dx + vol2* q[ecell[2*i+1]*4+2] - p2*dx) + mu*(q[ecell[2*i+0]*4+2]-q[ecell[2*i+1]*4+2]);
        	            res[ecell[2*i+0]*4+2] += f;
        	            res[ecell[2*i+1]*4+2] -= f;
        	            f = 0.5f*(vol1*(q[ecell[2*i+0]*4+3]+p1)     + vol2*(q[ecell[2*i+1]*4+3]+p2)    ) + mu*(q[ecell[2*i+0]*4+3]-q[ecell[2*i+1]*4+3]);
        	            res[ecell[2*i+0]*4+3] += f;
        	            res[ecell[2*i+1]*4+3] -= f;
    	            }
                }
                #pragma omp single
                {
                    wall_t_a = omp_get_wtime();
                    flux_res += (wall_t_a - wall_t_b);
                    // Apply boundary conditions
                    wall_t_b = omp_get_wtime();

                    for (int i = 0; i < nbedge; i++) {
                        double dx,dy,mu, ri, p1,vol1, p2,vol2, f;

                        dx = x[bedge[2*i+0]*2+0] - x[bedge[2*i+1]*2+0];
                        dy = x[bedge[2*i+0]*2+1] - x[bedge[2*i+1]*2+1];

                        ri = 1.0f/q[becell[i]*4+0];
                        p1 = gm1*(q[becell[i]*4+3]-0.5f*ri*(q[becell[i]*4+1]*q[becell[i]*4+1]+q[becell[i]*4+2]*q[becell[i]*4+2]));

                        if (bound[i]==1) { //Far-field
                            res[becell[i]*4+1] += + p1*dy;
                            res[becell[i]*4+2] += - p1*dx;
                        }
                        else {
                            vol1 =  ri*(q[becell[i]*4+1]*dy - q[becell[i]*4+2]*dx);

                            ri   = 1.0f/qinf[0];
                            p2   = gm1*(qinf[3]-0.5f*ri*(qinf[1]*qinf[1]+qinf[2]*qinf[2]));
                            vol2 =  ri*(qinf[1]*dy - qinf[2]*dx);

                            mu = adt[becell[i]]*eps;

                            f = 0.5f*(vol1* q[becell[i]*4+0]         + vol2* qinf[0]        ) + mu*(q[becell[i]*4+0]-qinf[0]);
                            res[becell[i]*4+0] += f;
                            f = 0.5f*(vol1* q[becell[i]*4+1] + p1*dy + vol2* qinf[1] + p2*dy) + mu*(q[becell[i]*4+1]-qinf[1]);
                            res[becell[i]*4+1] += f;
                            f = 0.5f*(vol1* q[becell[i]*4+2] - p1*dx + vol2* qinf[2] - p2*dx) + mu*(q[becell[i]*4+2]-qinf[2]);
                            res[becell[i]*4+2] += f;
                            f = 0.5f*(vol1*(q[becell[i]*4+3]+p1)     + vol2*(qinf[3]+p2)    ) + mu*(q[becell[i]*4+3]-qinf[3]);
                            res[becell[i]*4+3] += f;
                        }
                    }
                    wall_t_a = omp_get_wtime();
                    perem += (wall_t_a - wall_t_b);

                    // update flow field
                    wall_t_b = omp_get_wtime();
                    rms = 0.0;
                }

                #pragma omp for reduction(+:rms)
                for (int i = 0; i < ncell; i++) {
                    double del, adti;

                    adti = 1.0f/adt[i];

                    for (int n=0; n<4; n++) {
                        del    = adti*res[4*i+n];
                        q[4*i+n]   = qold[4*i+n] - del;
                        res[4*i+n] = 0.0f;
                        rms  += del*del;
                    }
                }

                #pragma omp single
                {
                    wall_t_a = omp_get_wtime();
                    update += (wall_t_a - wall_t_b);
                }
            }

	        #pragma omp single
            {
                rms = sqrt(rms/(double) ncell);
                if (iter%100 == 0){
    	        printf(" %d  %10.5e \n",iter,rms);
    	        printf("\tsave: %f\n",save);
    	        printf("\tarea: %f\n",area);
    	        printf("\tflux_res: %f\n",flux_res);
    	        printf("\tperem: %f\n",perem);
    	        printf("\tupdate: %f\n",update);
                char buf[50];
                sprintf(buf,"out%d.vtk",iter);
                WriteMeshToVTKAscii(buf, x, nnode, cell, ncell, q);
                }
            }
        }
    }

    wall_t2 = omp_get_wtime();
    printf("Max total runtime = \n%f\n",wall_t2-wall_t1);

    */
}

// 把一个double变量从一般格式转换成二进制格式
double Mesh::convert2BinaryDouble(double d) {
    union {
        double d;
        char b[8];
    } dat1, dat2;

    dat1.d = d;
    dat2.b[0] = dat1.b[7];
    dat2.b[1] = dat1.b[6];
    dat2.b[2] = dat1.b[5];
    dat2.b[3] = dat1.b[4];
    dat2.b[4] = dat1.b[3];
    dat2.b[5] = dat1.b[2];
    dat2.b[6] = dat1.b[1];
    dat2.b[7] = dat1.b[0];

    return dat2.d;
}

// 把一个float变量从一般格式转换成二进制格式
float Mesh::convert2BinaryFloat(float f) {
    union {
        float f;
        char b[4];
    } dat1, dat2;

    dat1.f = f;
    dat2.b[0] = dat1.b[3];
    dat2.b[1] = dat1.b[2];
    dat2.b[2] = dat1.b[1];
    dat2.b[3] = dat1.b[0];

    return dat2.f;
}

// 把一个int变量从一般格式转换成二进制格式
int Mesh::convert2BinaryInt(int d) {
    union {
        int d;
        char b[4];
    } dat1, dat2;

    dat1.d = d;
    dat2.b[0] = dat1.b[3];
    dat2.b[1] = dat1.b[2];
    dat2.b[2] = dat1.b[1];
    dat2.b[3] = dat1.b[0];

    return dat2.d;
}

// 把仿真结果写入VTK Ascii文件中
bool Mesh::writeToVTKAscii(FILE* fp) {
    if (fp == NULL) {
        printf("can't open ascii file.\n");
        return false;
    }

    // 写入文件头
    fprintf(fp, "# vtk DataFile Version 0.0 #\n");
    fprintf(fp, "ASCII \nDATASET UNSTRUCTURED_GRID\n");

    // 写入节点的信息
    fprintf(fp, "\nnode number: %d\n", node_num);
    for (int i = 0; i < node_num; ++i) {
        fprintf(fp, "%g %g \n", nodes[i][0], nodes[i][1]);
    }

    // 写入单元的信息
    fprintf(fp, "\ncell number: %d\n", cell_num);
    for (int i = 0; i < cell_num; ++i) {
        fprintf(fp, "%d %d %d %d \n", cells[i][0], cells[i][1],
                cells[i][2], cells[i][3]);
    }

    // 写入value的信息
    fprintf(fp, "\nvalues: %d(line)\n", values.size());
    for (int i = 0; i < values.size(); i++) {
        for (int j = 0; j < values[i].size(); j++) {
            fprintf(fp, "%10.20g ", values[i][j]);
        }
        fprintf(fp, "\n");
    }

    return true;
}

// 把仿真结果写入VTK Binary文件中
bool Mesh::writeToVTKBinary(FILE* fp) {
    if (fp == NULL) {
        printf("can't open binary file.\n");
        return false;
    }

    // 写入文件头
    fprintf(fp, "# vtk DataFile Version 0.0 #\n");
    fprintf(fp, "BINARY \nDATASET UNSTRUCTURED_GRID\n");

    // 写入节点的信息
    fprintf(fp, "\nnode number: %d\n", node_num);
    for (int i = 0; i < node_num; ++i) {
        fprintf(fp, "%g %g \n", convert2BinaryDouble(nodes[i][0]),
                convert2BinaryDouble(nodes[i][1]));
    }

    // 写入单元的信息
    fprintf(fp, "\ncell number: %d\n", cell_num);
    for (int i = 0; i < cell_num; ++i) {
        fprintf(fp, "%d %d %d %d \n", convert2BinaryInt(cells[i][0]),
                convert2BinaryInt(cells[i][1]),
                convert2BinaryInt(cells[i][2]),
                convert2BinaryInt(cells[i][3]));
    }

    // 写入value的信息
    fprintf(fp, "\nvalues: %d(line)\n", values.size());
    for (int i = 0; i < values.size(); i++) {
        for (int j = 0; j < values[i].size(); j++) {
            fprintf(fp, "%10.20g ", convert2BinaryDouble(values[i][j]));
        }
        fprintf(fp, "\n");
    }

    return true;
}