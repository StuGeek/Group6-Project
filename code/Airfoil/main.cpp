#include<iostream>
#include"meshloader.h"
#include"mesh.h"

int main() {

	MeshLoader loader;
	loader.load();

	Mesh m;
	m.setNodes(loader.getNodes());
	m.setCells(loader.getCells());
	m.setEdges(loader.getEdges());
	m.setBedges(loader.getBoundEdges());

	return 0;
}