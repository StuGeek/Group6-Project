#include<iostream>
#include"meshloader.h"
#include"mesh.h"


void Mesh::setNodes(vector<Node> _nodes) {
	nodes = _nodes;
}

void Mesh::setCells(vector<Cell> _cells) {
	cells = _cells;
}

void Mesh::setEdges(vector<Edge> _edges) {
	edges = _edges;
}

void Mesh::setBedges(vector<Bedge> _bedges) {
	bedges = _bedges;
}