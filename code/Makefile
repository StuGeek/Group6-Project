g++ main.cpp data.cpp -o main -O3 -fopenmp

main: main.cpp Makefile
	g++ main.cpp -o main.o -O3 -fopenmp

data: data.cpp Makefile
	g++ data.cpp -o data.o -O3 -fopenmp

run:
	main

clean:
	rm main
	rm .vtk