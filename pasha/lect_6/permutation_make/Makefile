# mingw32-make

permutation: main.o permutation.o
	g++ main.o permutation.o -o permutation

main.o: main.cpp permutation.h
	g++ -c main.cpp
	
permutation.o: permutation.cpp permutation.h
	g++ -c permutation.cpp