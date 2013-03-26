prog: main.o permutation.o
	g++ main.o permutation.o -s -o prog

permutation.o: permutation.cpp permutation.h
	g++ permutation.cpp -c

main.o: main.cpp permutation.h
	g++ main.cpp -c
