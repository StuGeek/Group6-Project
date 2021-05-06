#ifndef _EDGE_H_
#define _EDGE_H_
#include"cell.h"
#include"node.h"

class Edge
{
public:
	Edge(Node _n1, Node _n2, Cell _c1, Cell _c2) {
		n1 = _n1;
		n2 = _n2;
		c1 = _c1;
		c2 = _c2;
	}
private:
	Node n1;
	Node n2;
	Cell c1;
	Cell c2;
};



#endif