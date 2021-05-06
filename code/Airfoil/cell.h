#ifndef _CELL_H_
#define _CELL_H_
#include"node.h"

class Cell
{
public:
	Cell(){}
	Cell(Node _n1, Node _n2, Node _n3, Node _n4) {
		n1 = _n1;
		n2 = _n2;
		n3 = _n3;
		n4 = _n4;
	}
private:
	Node n1;
	Node n2;
	Node n3;
	Node n4;
};
#endif