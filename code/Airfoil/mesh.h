#ifndef _MESH_H_
#define _MESH_H_
#include<iostream>
#include"node.h"
#include"bedge.h"
#include"cell.h"
#include<vector>

using namespace std;

class Mesh
{
public:
	void setNodes(vector<Node> _nodes);
	void setCells(vector<Cell> _cells);
	void setEdges(vector<Edge> _edges);
	void setBedges(vector<Bedge> _bedges);

private:
	vector<Node> nodes;
	vector<Cell> cells;
	vector<Edge> edges;
	vector<Bedge> bedges;
};

#endif