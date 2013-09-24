prog: main.o a.o a1.o a2.o
	$(CXX) -o $@ $^
main.o: main.cpp a.h a1.h a2.h
a.o: a.cpp a.h
a1.o: a1.cpp a1.h
a2.o: a2.cpp a2.h