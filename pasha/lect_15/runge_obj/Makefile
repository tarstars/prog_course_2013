runge: circlewalk.o poly_eq.o main.o
	$(CXX) -o $@ $^
main.o: main.cpp circlewalk.h poly_eq.h solvable.h
circlewalk.o: circlewalk.cpp circlewalk.h solvable.h
poly_eq.o: poly_eq.cpp poly_eq.h solvable.h