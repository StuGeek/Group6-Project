#ifndef _ELEMENTt_H_
#define _ELEMENTt_H_

#include <iostream>
#include <cmath>
#include <vector>

typedef double real;

class Node {
public:
    Node() {}
    Node(real t_x = 0, real t_y = 0) : x(t_x), y(t_y) {}

    real getx();
    real gety();

private:
    real x, y;
};

class Cell {
public:
    Cell() {}
    Cell(int t_n1, int t_n2, int t_n3, int t_n4) : n1(t_n1), n2(t_n2), n3(t_n3), n4(t_n4) {}

    int getn1();
    int getn2();
    int getn3();
    int getn4();

private:
    int n1, n2, n3, n4;
};

class Edge {
public:
    Edge() {}
    Edge(int t_n1, int t_n2, int t_c1, int t_c2) : n1(t_n1), n2(t_n2), c1(t_c1), c2(t_c2) {}

    int getn1();
    int getn2();
    int getc1();
    int getc2();
    
private:
    int n1, n2;
    int c1, c2;
};

class Bedge {
public:
    Bedge() {}
    Bedge(int t_n1, int t_n2, int t_c, int t_b) : n1(t_n1), n2(t_n2), c(t_c), b(t_b) {}

    int getn1();
    int getn2();
    int getc();
    int getb();

private:
    int n1, n2;
    int c, b;
};

class Mesh {
public:
    Mesh() {}
    Mesh(int t_nnode, int t_ncell, int t_nedge, int t_nbedge) : nnode(t_nnode), ncell(t_ncell), nedge(t_nedge), nbedge(t_nbedge) {}
    Mesh(const Mesh & t_mesh);
    Mesh(const char* pathname);

    int getnnode();
    int getncell();
    int getnedge();
    int getnbedge();

	void setNodes(std::vector<Node>& t_nodes);
	void setCells(std::vector<Cell>& t_cells);
	void setEdges(std::vector<Edge>& t_edges);
	void setBedges(std::vector<Bedge>& t_bedges);

    std::vector<Node> getNodes();
	std::vector<Cell> getCells();
	std::vector<Edge> getEdges();
	std::vector<Bedge> getBedges();
    std::vector<std::vector<int> > getColor2Edge();

    void pushNode(Node node);
    void pushCell(Cell cell);
    void pushEdge(Edge edge);
    void pushBedge(Bedge bedge);

    bool popNode();
    bool popCell();
    bool popEdge();
    bool popBedge();

    void colorGragh();  // 为图像染色

    // 读入grid数据文件
    void readGrid(const char* pathname);
    void WriteMeshToVTKAscii(const char* filename, std::vector<Node> & nodeCoords_data, int nnode, std::vector<Cell> & cellsToNodes_data, int ncell, std::vector<double> & values_data);
    void WriteMeshToVTKBinary(const char* filename, std::vector<Node> & nodeCoords_data, int nnode, std::vector<Cell> & cellsToNodes_data, int ncell, std::vector<double> & values_data);

protected:
    int nnode, ncell, nedge, nbedge;

	std::vector<Node> nodes;
	std::vector<Cell> cells;
	std::vector<Edge> edges;
	std::vector<Bedge> bedges;

    std::vector<std::vector<int> > color2edge;

    inline double swapEndiannesDouble(double d);
    inline float swapEndiannesFloat(float f);
    inline int swapEndiannesInt(int d);
};

class FlowField : public Mesh {
public:
    FlowField() {}
    FlowField(const Mesh & t_mesh);

    void initFlowField(); // 初始化流场

    real getgam();
    real getgm1();
    real getcfl();
    real geteps();
    real* getqinf();

    std::vector<real> getq();
    std::vector<real> getres();
    std::vector<real> getadt();

    void calculate(int niter);  // 计算流场的各项数值
    void resetTimer();          // 重置计时器

public:
    real gam, gm1, cfl, eps, qinf[4];
    std::vector<real> q;
    std::vector<real> res;
    std::vector<real> adt;

    // 计时器
    struct Timer {
        double save;      // 保存旧的流解决方案的总时间
        double area;      // 预测器/校正器更新循环的总时间
        double flux_res;  // 计算flux residual的的总时间
        double perem;     // 计算应用边界条件的总时间
        double update;    // 计算更新流场的总时间
        double wall_t1;   // 总的计算的开始时间
        double wall_t2;   // 总的计算的结束时间
    } timer;

};

#endif