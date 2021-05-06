#ifndef _BEDGE_H_
#define _BEDGE_H_
class Bedge
{
public:
	Bedge(Node _n1, Node _n2, Cell _c, Cell _b) {
		n1 = _n1;
		n2 = _n2;
		c = _c;
		b = _b;
	}

private:
	Node n1;
	Node n2;
	Cell c;
	Cell b;
};
#endif