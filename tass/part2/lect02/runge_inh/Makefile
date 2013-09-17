runge:  circle_walk.o poly_eq.o main.o
	$(CXX) -o $@ $^
main.o: main.cpp circle_walk.h poly_eq.h solvable.h
circle_walk.o: circle_walk.cpp circle_walk.h solvable.h
poly_eq: poly_eq.cpp poly_eq.h solvable.h
