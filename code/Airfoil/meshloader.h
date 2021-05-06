#ifndef _MESHLOADER_H_
#define _MESHLOADER_H_
#include<iostream>
#include<vector>
#include"edge.h"
#include"bedge.h"

using namespace std;

class MeshLoader
{
public:
	int load();
	int getNodeNumber() { return node_num; }
	int getCellNumber() { return cell_num; }
	int getEdgeNumber() { return edge_num; }
	int getBEdgeNumber() { return bedge_num; }

	vector<Node> getNodes();
	vector<Edge> getEdges();
	vector<Bedge> getBoundEdges();
	vector<Cell> getCells();

private:
	vector<double> x_vals; //2
	vector<int> cell_vals; //4
	vector<int> edge_vals; //4
	vector<int> ecell_vals;
	vector<int> bedge_vals;
	vector<int> becell_vals;
	vector<int> bound_vals;

	int node_num;
	int cell_num;
	int edge_num;
	int bedge_num;

};

#endif