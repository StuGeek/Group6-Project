// g++ main.cpp data.cpp -o main -O3 -fopenmp

#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

#include "data.h"

typedef double real;

int main(int argc, char **argv)
{
	char pathname[100] = {"./new_grid.dat"};
	Mesh t_mesh(pathname);

	FlowField flowfield(t_mesh);

	// 迭代次数
	int niter;
	niter = 1000;

	flowfield.calculate(niter);

}
