# mingw32-make

3vector: main.o myvect.o
	g++ main.o myvect.o -o myvect

main.o: main.cpp myvect.h
	g++ -c main.cpp
	
myvect.o: myvect.cpp myvect.h
	g++ -c myvect.cpp