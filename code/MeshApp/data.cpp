#include <iostream>
#include <vector>
#include <string.h>
#include <omp.h>
#include "data.h"
#include <qdebug.h>

#define N_STATEVAR 4

real Node::getx() { return x; }
real Node::gety() { return y; }

int Cell::getn1() { return n1; }
int Cell::getn2() { return n2; }
int Cell::getn3() { return n3; }
int Cell::getn4() { return n4; }

int Edge::getn1() { return n1; }
int Edge::getn2() { return n2; }
int Edge::getc1() { return c1; }
int Edge::getc2() { return c2; }

int Bedge::getn1() { return n1; }
int Bedge::getn2() { return n2; }
int Bedge::getc() { return c; }
int Bedge::getb() { return b; }


Mesh::Mesh(const Mesh& t_mesh) {
	nnode = t_mesh.nnode;
	ncell = t_mesh.ncell;
	nedge = t_mesh.nedge;
	nbedge = t_mesh.nbedge;

	nodes = t_mesh.nodes;
	cells = t_mesh.cells;
	edges = t_mesh.edges;
	bedges = t_mesh.bedges;

	color2edge = t_mesh.color2edge;
}

Mesh::Mesh(const char* pathname) {
	readGrid(pathname);
}

int Mesh::getnnode() { return nnode; }
int Mesh::getncell() { return ncell; }
int Mesh::getnedge() { return nedge; }
int Mesh::getnbedge() { return nbedge; }

void Mesh::setNodes(std::vector<Node>& t_nodes) { nodes = t_nodes; }
void Mesh::setCells(std::vector<Cell>& t_cells) { cells = t_cells; }
void Mesh::setEdges(std::vector<Edge>& t_edges) { edges = t_edges; }
void Mesh::setBedges(std::vector<Bedge>& t_bedges) { bedges = t_bedges; }

std::vector<Node> Mesh::getNodes() { return nodes; }
std::vector<Cell> Mesh::getCells() { return cells; }
std::vector<Edge> Mesh::getEdges() { return edges; }
std::vector<Bedge> Mesh::getBedges() { return bedges; }
std::vector<std::vector<int> > Mesh::getColor2Edge() { return color2edge; }

void Mesh::pushNode(Node node) { nodes.push_back(node); }
void Mesh::pushCell(Cell cell) { cells.push_back(cell); }
void Mesh::pushEdge(Edge edge) { edges.push_back(edge); }
void Mesh::pushBedge(Bedge bedge) { bedges.push_back(bedge); }

bool Mesh::popNode() {
	if (nodes.empty()) return false;
	nodes.pop_back();
	return true;
}

bool Mesh::popCell() {
	if (cells.empty()) return false;
	cells.pop_back();
	return true;
}

bool Mesh::popEdge() {
	if (edges.empty()) return false;
	edges.pop_back();
	return true;
}

bool Mesh::popBedge() {
	if (bedges.empty()) return false;
	bedges.pop_back();
	return true;
}

// Ϊͼ��Ⱦɫ���õ�Mesh�ĳ�Ա�����Ķ�ά����color2edge
void Mesh::colorGragh() {
	std::vector<int> cell2edge(4 * ncell, -1);
	std::vector<int> edge2color(nedge, -1);

	for (int n = 0; n < nedge; n++) {
		int c1 = edges[n].getc1();
		int c2 = edges[n].getc2();

		for (int i = 0; i < 4; ++i) {
			if (cell2edge[c1 + i] == -1) {
				cell2edge[c1 + i] = n;
				break;
			}
		}

		for (int i = 0; i < 4; ++i) {
			if (cell2edge[c2 + i] == -1) {
				cell2edge[c2 + i] = n;
				break;
			}
		}
	}

	int max = 0;

	for (int edge_ind = 0; edge_ind < nedge; ++edge_ind) {
		int color = 0;
		while (1) {
			bool valid_color = true;
			for (int i = 0; i < 4; ++i) {
				if (edge_ind % 2 == 0) {
					if (edge2color[cell2edge[edges[edge_ind / 2].getc1() + i]] == color ||
						edge2color[cell2edge[edges[edge_ind / 2].getc2() + i]] == color) {
						valid_color = false;
					}
				}
				else {
					if (edge2color[cell2edge[edges[edge_ind / 2 + 1].getc1() + i]] == color ||
						edge2color[cell2edge[edges[edge_ind / 2].getc2() + i]] == color) {
						valid_color = false;
					}
				}
			}
			if (valid_color) {
				edge2color[edge_ind] = color;
				if (color2edge.size() == color) {
					color2edge.push_back(std::vector<int>(1, edge_ind));
				}
				else if (color < color2edge.size()) {
					color2edge[color].push_back(edge_ind);
				}
				else {
					printf("ismet para van\n");
				}
				if (color > max) {
					max = color;
					printf("%d\n", max);
				}
				break;
			}
			++color;
		}
	}

	printf("%d %d %d %d %d %d", color2edge[0].size(), color2edge[1].size(), color2edge[2].size(),
		color2edge[3].size(), color2edge[4].size(), color2edge[5].size());
}

// ����grid�����ļ�
void Mesh::readGrid(const char* pathname) {
	double x, y;
	int n1, n2, n3, n4, c1, c2, c, b;

	// read in grid
	printf("reading in grid \n");

	FILE* fp;
	if ((fp = fopen(pathname, "r")) == NULL) {
		printf("can't open file new_grid.dat\n");
		exit(-1);
	}

	if (fscanf(fp, "%d %d %d %d \n", &nnode, &ncell, &nedge, &nbedge) != 4) {
		printf("error reading from new_grid.dat\n");
		exit(-1);
	}

	for (int n = 0; n < nnode; n++) {
		if (fscanf(fp, "%lf %lf \n", &x, &y) != 2) {
			printf("error reading from new_grid.dat\n");
			exit(-1);
		}
		pushNode(Node(x, y));
	}

	for (int n = 0; n < ncell; n++) {
		if (fscanf(fp, "%d %d %d %d \n", &n1, &n2, &n3, &n4) != 4) {
			printf("error reading from new_grid.dat\n");
			exit(-1);
		}
		pushCell(Cell(n1, n2, n3, n4));
	}

	for (int n = 0; n < nedge; n++) {
		if (fscanf(fp, "%d %d %d %d \n", &n1, &n2, &c1, &c2) != 4) {
			printf("error reading from new_grid.dat\n");
			exit(-1);
		}
		pushEdge(Edge(n1, n2, c1, c2));
	}

	for (int n = 0; n < nbedge; n++) {
		if (fscanf(fp, "%d %d %d %d \n", &n1, &n2, &c, &b) != 4) {
			printf("error reading from new_grid.dat\n");
			exit(-1);
		}
		pushBedge(Bedge(n1, n2, c, b));
	}

	fclose(fp);

	colorGragh();
}

void Mesh::WriteMeshToVTKAscii(const char* filename, std::vector<Node>& nodeCoords_data, int nnode, std::vector<Cell>& cellsToNodes_data, int ncell, std::vector<double>& values_data) {
	printf("Writing OutputSimulation to ASCII file: %s \n", filename);
	FILE* fp;
	fp = fopen(filename, "w");
	if (fp == NULL) {
		printf("can't open file for write %s\n", filename);
		exit(-1);
	}

	// write header
	fprintf(fp, "# vtk DataFile Version 2.0\n Output from OP2 Volna.\n");
	fprintf(fp, "ASCII \nDATASET UNSTRUCTURED_GRID\n\n");
	// write vertices
	fprintf(fp, "POINTS %d double\n", nnode);
	//  double* nodeCoords_data;
	//  nodeCoords_data = (double*)nodeCoords->data;
	int i = 0;
	for (i = 0; i < nnode; ++i) {
		fprintf(fp, "%g %g %g \n",
			(double)nodeCoords_data[i].getx(),
			(double)nodeCoords_data[i].gety(),
			0.0);
	}
	fprintf(fp, "\n");
	fprintf(fp, "CELLS %d %d\n", ncell, 5 * ncell);
	for (i = 0; i < ncell; ++i) {
		fprintf(fp, "4 %d %d %d %d\n",
			cellsToNodes_data[i].getn1(),
			cellsToNodes_data[i].getn2(),
			cellsToNodes_data[i].getn3(),
			cellsToNodes_data[i].getn4());
	}
	fprintf(fp, "\n");
	// write cell types (5 for triangles, 9 for quads)
	fprintf(fp, "CELL_TYPES %d\n", ncell);
	for (i = 0; i < ncell; ++i)
		fprintf(fp, "9\n");
	fprintf(fp, "\n");

	//  double* values_data;
	//  values_data = (double*) values->data;

	fprintf(fp,
		"CELL_DATA %d\n"
		"SCALARS q0 double 1\n"
		"LOOKUP_TABLE default\n",
		ncell);
	double tmp = 0.0;
	for (i = 0; i < ncell; ++i) {
		tmp = values_data[i * N_STATEVAR];
		fprintf(fp, "%10.20g\n", values_data[i * N_STATEVAR]);
	}

	fprintf(fp, "\n");
	fprintf(fp,
		"SCALARS q1 double 1\n"
		"LOOKUP_TABLE default\n");
	for (i = 0; i < ncell; ++i)
		fprintf(fp, "%10.20g\n", values_data[i * N_STATEVAR + 1]);
	fprintf(fp, "\n");
	fprintf(fp,
		"SCALARS q2 double 1\n"
		"LOOKUP_TABLE default\n");
	for (i = 0; i < ncell; ++i)
		fprintf(fp, "%10.20g\n", values_data[i * N_STATEVAR + 2]);
	fprintf(fp, "\n");
	fprintf(fp,
		"SCALARS q3 double 1\n"
		"LOOKUP_TABLE default\n");
	for (i = 0; i < ncell; ++i)
		fprintf(fp, "%10.20g\n", values_data[i * N_STATEVAR + 3]);
	fprintf(fp, "\n");

	if (fclose(fp) != 0) {
		printf("can't close file %s\n", filename);
		exit(-1);
	}
}

void Mesh::WriteMeshToVTKBinary(const char* filename, std::vector<Node>& nodeCoords_data, int nnode, std::vector<Cell>& cellsToNodes_data, int ncell, std::vector<double>& values_data) {
	printf("Writing OutputSimulation to binary file: %s \n", filename);
	FILE* fp;
	fp = fopen(filename, "w");
	if (fp == NULL) {
		printf("can't open file for write %s\n", filename);
		exit(-1);
	}

	// write header
	char s[256];
	strcpy(s, "# vtk DataFile Version 2.0\n Output from OP2 Volna.\n");
	fwrite(s, sizeof(char), strlen(s), fp);
	strcpy(s, "BINARY \nDATASET UNSTRUCTURED_GRID\n\n");
	fwrite(s, sizeof(char), strlen(s), fp);

	// write vertices
	sprintf(s, "POINTS %d double\n", nnode);
	fwrite(s, sizeof(char), strlen(s), fp);

	//double* nodeCoords_data;
	//nodeCoords_data = (double*)nodeCoords->data;
	double tmp_double;
	int i = 0;
	for (i = 0; i < nnode; ++i) {
		tmp_double = swapEndiannesDouble(nodeCoords_data[i].getx());
		fwrite(&tmp_double, sizeof(double), 1, fp);
		tmp_double = swapEndiannesDouble(nodeCoords_data[i].gety());
		fwrite(&tmp_double, sizeof(double), 1, fp);
		tmp_double = swapEndiannesDouble(0.0);
		fwrite(&tmp_double, sizeof(double), 1, fp);
	}
	strcpy(s, "\n");
	fwrite(s, sizeof(char), strlen(s), fp);

	// write cells
	sprintf(s, "CELLS %d %d\n", ncell, 5 * ncell);
	fwrite(s, sizeof(char), strlen(s), fp);

	int three = 3;
	int tmp_int;
	for (i = 0; i < ncell; ++i) {
		tmp_int = swapEndiannesInt(three);
		fwrite(&tmp_int, sizeof(int), 1, fp);
		tmp_int = swapEndiannesInt(cellsToNodes_data[i].getn1());
		fwrite(&tmp_int, sizeof(int), 1, fp);
		tmp_int = swapEndiannesInt(cellsToNodes_data[i].getn2());
		fwrite(&tmp_int, sizeof(int), 1, fp);
		tmp_int = swapEndiannesInt(cellsToNodes_data[i].getn3());
		fwrite(&tmp_int, sizeof(int), 1, fp);
		tmp_int = swapEndiannesInt(cellsToNodes_data[i].getn4());
		fwrite(&tmp_int, sizeof(int), 1, fp);
	}
	strcpy(s, "\n");
	fwrite(s, sizeof(char), strlen(s), fp);

	// write cell types (5 for triangles)
	sprintf(s, "CELL_TYPES %d\n", ncell);
	fwrite(s, sizeof(char), strlen(s), fp);

	int five = 9;  //five triangles 9 quads
	for (i = 0; i < ncell; ++i) {
		tmp_int = swapEndiannesInt(five);
		fwrite(&tmp_int, sizeof(int), 1, fp);
	}

	strcpy(s, "\n");
	fwrite(s, sizeof(char), strlen(s), fp);
	//double* values_data;
	//values_data = (double*) values->data;
	sprintf(s,
		"CELL_DATA %d\n"
		"SCALARS q0 double 1\n"
		"LOOKUP_TABLE default\n",
		ncell);
	fwrite(s, sizeof(char), strlen(s), fp);

	for (i = 0; i < ncell; ++i) {
		tmp_double = swapEndiannesDouble(values_data[i * N_STATEVAR]);
		fwrite(&tmp_double, sizeof(double), 1, fp);
	}

	strcpy(s, "\n");
	fwrite(s, sizeof(char), strlen(s), fp);

	strcpy(s, "SCALARS q1 double 1\nLOOKUP_TABLE default\n");
	fwrite(s, sizeof(char), strlen(s), fp);
	for (i = 0; i < ncell; ++i) {
		tmp_double = swapEndiannesDouble(values_data[i * N_STATEVAR + 1]);
		fwrite(&tmp_double, sizeof(double), 1, fp);
	}
	strcpy(s, "\n");
	fwrite(s, sizeof(char), strlen(s), fp);

	strcpy(s, "SCALARS q2 double 1\nLOOKUP_TABLE default\n");
	fwrite(s, sizeof(char), strlen(s), fp);
	for (i = 0; i < ncell; ++i) {
		tmp_double = swapEndiannesDouble(values_data[i * N_STATEVAR + 2]);
		fwrite(&tmp_double, sizeof(double), 1, fp);
	}

	strcpy(s, "\n");
	fwrite(s, sizeof(char), strlen(s), fp);

	strcpy(s, "SCALARS q3 double 1\nLOOKUP_TABLE default\n");
	fwrite(s, sizeof(char), strlen(s), fp);
	for (i = 0; i < ncell; ++i) {
		tmp_double = swapEndiannesDouble(values_data[i * N_STATEVAR + 3]);
		fwrite(&tmp_double, sizeof(double), 1, fp);
	}

	strcpy(s, "\n");
	fwrite(s, sizeof(char), strlen(s), fp);

	if (fclose(fp) != 0) {
		printf("can't close file %s\n", filename);
		exit(-1);
	}
}

inline double Mesh::swapEndiannesDouble(double d) {
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

inline float Mesh::swapEndiannesFloat(float f) {
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

inline int Mesh::swapEndiannesInt(int d) {
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

FlowField::FlowField(const Mesh& t_mesh) : Mesh(t_mesh) { initFlowField(); }

// ��ʼ������
void FlowField::initFlowField() {
#pragma omp for
	for (int i = 0; i < ncell; i++) {
		for (int n = 0; n < 4; n++) {
			q.push_back(0);
			res.push_back(0);
		}
		adt.push_back(0);
	}

	printf("initialising flow field \n");

	gam = 1.4f;
	gm1 = gam - 1.0f;
	cfl = 0.9f;
	eps = 0.05f;

	real mach = 0.4f;
	real alpha = 3.0f * atan(1.0f) / 45.0f;
	real p = 1.0f;
	real r = 1.0f;
	real u = sqrt(gam * p / r) * mach;
	real e = p / (r * gm1) + 0.5f * u * u;

	qinf[0] = r;
	qinf[1] = r * u;
	qinf[2] = 0.0f;
	qinf[3] = r * e;

	for (int n = 0; n < ncell; n++) {
		for (int m = 0; m < 4; m++) {
			q[4 * n + m] = qinf[m];
			res[4 * n + m] = 0.0f;
		}
	}

	resetTimer();
}

real FlowField::getgam() { return gam; }
real FlowField::getgm1() { return gm1; }
real FlowField::getcfl() { return cfl; }
real FlowField::geteps() { return eps; }
real* FlowField::getqinf() { return qinf; }

std::vector<real> FlowField::getq() { return q; }
std::vector<real> FlowField::getres() { return res; }
std::vector<real> FlowField::getadt() { return adt; }

// ���������ĸ�����ֵ
void FlowField::calculate(int niter) {
	// ���ü�ʱ��
	resetTimer();

	// ������
	real rms;

	// �ɵ����������
	std::vector<real> qold(4 * ncell);

	//initialise timers for total execution wall time ��ȡ���㿪ʼʱ���
	timer.wall_t1 = omp_get_wtime();

	// main time-marching loop �����������
	double wall_t_a = 0, wall_t_b = 0;
#pragma omp parallel
	{
		// ����niter�ε���
		for (int iter = 1; iter <= niter; iter++) {
			setCalculateProgress(iter * 100 / niter);
			// ���Ȼ�ȡʱ�䱣����wall_t_b��
#pragma omp single
			{
				wall_t_b = omp_get_wtime();
			}

			// save old flow solution ����ɵ��������������q�е����ݸ��Ƶ�qold��
#pragma omp for
			for (int i = 0; i < ncell; i++) {
				for (int n = 0; n < 4; n++) {
					qold[4 * i + n] = q[4 * i + n];
				}
			}

			// �ٴλ�ȡʱ�䣬������ɵ������������ʱ��ӵ�save��
#pragma omp single
			{
				wall_t_a = omp_get_wtime();
				timer.save += wall_t_a - wall_t_b;
			}

			// predictor/corrector update loop Ԥ����/У��������ѭ��
			for (int k = 0; k < 2; k++) {

				// ���Ȼ�ȡÿ��ѭ�����¿�ʼ��ʱ���
#pragma omp single
				{
					wall_t_b = omp_get_wtime();
				}

				// calculate area/timstep �������/����
#pragma omp for
				for (int i = 0; i < ncell; i++) {
					double dx, dy, ri, u, v, c;

					ri = 1.0f / q[4 * i + 0];
					u = ri * q[4 * i + 1];
					v = ri * q[4 * i + 2];
					c = sqrt(gam * gm1 * (ri * q[4 * i + 3] - 0.5f * (u * u + v * v)));

					dx = nodes[cells[i].getn2()].getx() - nodes[cells[i].getn1()].getx();
					dy = nodes[cells[i].getn2()].gety() - nodes[cells[i].getn1()].gety();
					adt[i] = fabs(u * dy - v * dx) + c * sqrt(dx * dx + dy * dy);

					dx = nodes[cells[i].getn3()].getx() - nodes[cells[i].getn2()].getx();
					dy = nodes[cells[i].getn3()].gety() - nodes[cells[i].getn2()].gety();
					adt[i] += fabs(u * dy - v * dx) + c * sqrt(dx * dx + dy * dy);

					dx = nodes[cells[i].getn4()].getx() - nodes[cells[i].getn3()].getx();
					dy = nodes[cells[i].getn4()].gety() - nodes[cells[i].getn3()].gety();
					adt[i] += fabs(u * dy - v * dx) + c * sqrt(dx * dx + dy * dy);

					dx = nodes[cells[i].getn1()].getx() - nodes[cells[i].getn4()].getx();
					dy = nodes[cells[i].getn1()].gety() - nodes[cells[i].getn4()].gety();
					adt[i] += fabs(u * dy - v * dx) + c * sqrt(dx * dx + dy * dy);

					adt[i] = adt[i] / cfl;

				}

				// �ٴλ�ȡʱ�䣬���������/������ʱ��ӵ�area��
#pragma omp single
				{
					wall_t_a = omp_get_wtime();
					timer.area += (wall_t_a - wall_t_b);
					// calculate flux residual ��ȡ����flux residual�Ŀ�ʼʱ��
					wall_t_b = omp_get_wtime();
				}

				// ����flux residual
				for (size_t color = 0; color < color2edge.size(); ++color) {
#pragma omp for
					for (size_t ind = 0; ind < color2edge[color].size(); ++ind) {
						int i = color2edge[color][ind];
						double dx, dy, mu, ri, p1, vol1, p2, vol2, f;

						dx = nodes[edges[i].getn1()].getx() - nodes[edges[i].getn2()].getx();
						dy = nodes[edges[i].getn1()].gety() - nodes[edges[i].getn2()].gety();

						ri = 1.0f / q[edges[i].getc1() * 4 + 0];
						p1 = gm1 * (q[edges[i].getc1() * 4 + 3] - 0.5f * ri * (q[edges[i].getc1() * 4 + 1] * q[edges[i].getc1() * 4 + 1] + q[edges[i].getc1() * 4 + 2] * q[edges[i].getc1() * 4 + 2]));
						vol1 = ri * (q[edges[i].getc1() * 4 + 1] * dy - q[edges[i].getc1() * 4 + 2] * dx);

						ri = 1.0f / q[edges[i].getc2() * 4 + 0];
						p2 = gm1 * (q[edges[i].getc2() * 4 + 3] - 0.5f * ri * (q[edges[i].getc2() * 4 + 1] * q[edges[i].getc2() * 4 + 1] + q[edges[i].getc2() * 4 + 2] * q[edges[i].getc2() * 4 + 2]));
						vol2 = ri * (q[edges[i].getc2() * 4 + 1] * dy - q[edges[i].getc2() * 4 + 2] * dx);

						mu = 0.5f * (adt[edges[i].getc1()] + adt[edges[i].getc2()]) * eps;

						f = 0.5f * (vol1 * q[edges[i].getc1() * 4 + 0] + vol2 * q[edges[i].getc2() * 4 + 0]) + mu * (q[edges[i].getc1() * 4 + 0] - q[edges[i].getc2() * 4 + 0]);
						res[edges[i].getc1() * 4 + 0] += f;
						res[edges[i].getc2() * 4 + 0] -= f;
						f = 0.5f * (vol1 * q[edges[i].getc1() * 4 + 1] + p1 * dy + vol2 * q[edges[i].getc2() * 4 + 1] + p2 * dy) + mu * (q[edges[i].getc1() * 4 + 1] - q[edges[i].getc2() * 4 + 1]);
						res[edges[i].getc1() * 4 + 1] += f;
						res[edges[i].getc2() * 4 + 1] -= f;
						f = 0.5f * (vol1 * q[edges[i].getc1() * 4 + 2] - p1 * dx + vol2 * q[edges[i].getc2() * 4 + 2] - p2 * dx) + mu * (q[edges[i].getc1() * 4 + 2] - q[edges[i].getc2() * 4 + 2]);
						res[edges[i].getc1() * 4 + 2] += f;
						res[edges[i].getc2() * 4 + 2] -= f;
						f = 0.5f * (vol1 * (q[edges[i].getc1() * 4 + 3] + p1) + vol2 * (q[edges[i].getc2() * 4 + 3] + p2)) + mu * (q[edges[i].getc1() * 4 + 3] - q[edges[i].getc2() * 4 + 3]);
						res[edges[i].getc1() * 4 + 3] += f;
						res[edges[i].getc2() * 4 + 3] -= f;
					}
				}
				//for (int i = 0; i < nedge; i++) {

				//}

#pragma omp single
				{
					// �ٴλ�ȡʱ�䣬������flux residual��ʱ��ӵ�flux_res��
					wall_t_a = omp_get_wtime();
					timer.flux_res += (wall_t_a - wall_t_b);
					// Apply boundary conditions ��ȡ����Ӧ�ñ߽������Ŀ�ʼʱ��
					wall_t_b = omp_get_wtime();

					// ����Ӧ�ñ߽�����
					for (int i = 0; i < nbedge; i++) {
						double dx, dy, mu, ri, p1, vol1, p2, vol2, f;

						dx = nodes[bedges[i].getn1()].getx() - nodes[bedges[i].getn2()].getx();
						dy = nodes[bedges[i].getn1()].gety() - nodes[bedges[i].getn2()].gety();

						ri = 1.0f / q[bedges[i].getc() * 4 + 0];
						p1 = gm1 * (q[bedges[i].getc() * 4 + 3] - 0.5f * ri * (q[bedges[i].getc() * 4 + 1] * q[bedges[i].getc() * 4 + 1] + q[bedges[i].getc() * 4 + 2] * q[bedges[i].getc() * 4 + 2]));

						if (bedges[i].getb() == 1) { //Far-field
							res[bedges[i].getc() * 4 + 1] += +p1 * dy;
							res[bedges[i].getc() * 4 + 2] += -p1 * dx;
						}
						else {
							vol1 = ri * (q[bedges[i].getc() * 4 + 1] * dy - q[bedges[i].getc() * 4 + 2] * dx);

							ri = 1.0f / qinf[0];
							p2 = gm1 * (qinf[3] - 0.5f * ri * (qinf[1] * qinf[1] + qinf[2] * qinf[2]));
							vol2 = ri * (qinf[1] * dy - qinf[2] * dx);

							mu = adt[bedges[i].getc()] * eps;

							f = 0.5f * (vol1 * q[bedges[i].getc() * 4 + 0] + vol2 * qinf[0]) + mu * (q[bedges[i].getc() * 4 + 0] - qinf[0]);
							res[bedges[i].getc() * 4 + 0] += f;
							f = 0.5f * (vol1 * q[bedges[i].getc() * 4 + 1] + p1 * dy + vol2 * qinf[1] + p2 * dy) + mu * (q[bedges[i].getc() * 4 + 1] - qinf[1]);
							res[bedges[i].getc() * 4 + 1] += f;
							f = 0.5f * (vol1 * q[bedges[i].getc() * 4 + 2] - p1 * dx + vol2 * qinf[2] - p2 * dx) + mu * (q[bedges[i].getc() * 4 + 2] - qinf[2]);
							res[bedges[i].getc() * 4 + 2] += f;
							f = 0.5f * (vol1 * (q[bedges[i].getc() * 4 + 3] + p1) + vol2 * (qinf[3] + p2)) + mu * (q[bedges[i].getc() * 4 + 3] - qinf[3]);
							res[bedges[i].getc() * 4 + 3] += f;
						}
					}
					// �ٴλ�ȡʱ�䣬������Ӧ�ñ߽�������ʱ��ӵ�perem��
					wall_t_a = omp_get_wtime();
					timer.perem += (wall_t_a - wall_t_b);

					// update flow field ��ȡ���������Ŀ�ʼʱ��
					wall_t_b = omp_get_wtime();
					rms = 0.0;
				}

				// ��������
#pragma omp for reduction(+:rms)
				for (int i = 0; i < ncell; i++) {
					double del, adti;

					adti = 1.0f / adt[i];

					for (int n = 0; n < 4; n++) {
						del = adti * res[4 * i + n];
						q[4 * i + n] = qold[4 * i + n] - del;
						res[4 * i + n] = 0.0f;
						rms += del * del;
					}
				}

				// �ٴλ�ȡʱ�䣬���������������ʱ��ӵ�update��
#pragma omp single
				{
					wall_t_a = omp_get_wtime();
					timer.update += (wall_t_a - wall_t_b);
				}

			}

			// print iteration history ��ӡ������ʷ
#pragma omp single
			{
				rms = sqrt(rms / (double)ncell);
				setIterLabel(iter);
				setRmsLabel(iter);
				setTimerLabel(&timer);
				if (iter % 100 == 0) {
					printf(" %d  %10.5e \n", iter, rms);
					printf("\tsave: %f\n", timer.save);
					printf("\tarea: %f\n", timer.area);
					printf("\tflux_res: %f\n", timer.flux_res);
					printf("\tperem: %f\n", timer.perem);
					printf("\tupdate: %f\n", timer.update);
					char buf[50];
					sprintf(buf, "out%d.vtk", iter);
					WriteMeshToVTKAscii(buf, nodes, nnode, cells, ncell, q);
				}
			}
		}
	}

	// ��ȡ�������ʱ��
	timer.wall_t2 = omp_get_wtime();

	// ��ӡ����������ʱ��
	printf("Max total runtime = %f\n", timer.wall_t2 - timer.wall_t1);
}

// ���ü�ʱ�������еı���������Ϊ0
void FlowField::resetTimer() {
	timer.save = 0;
	timer.area = 0;
	timer.update = 0;
	timer.flux_res = 0;
	timer.perem = 0;
	timer.wall_t1 = 0;
	timer.wall_t2 = 0;
}

void FlowField::setCalculateProgress(int value) {
	emit __CalculateProgress_set(value);
	qDebug()<<"__CalculateProgress_set"<<endl;
}

void FlowField::setTimerLabel(struct Timer * timer) {
	emit __TimerLabel_set(timer);
}

void FlowField::setIterLabel(int _iter) {
	emit __iter_set(_iter);
}
void FlowField::setRmsLabel(int _rms) {
	emit __rms_set(_rms);
}