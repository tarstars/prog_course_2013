CXX=g++
TARGET=prog
CFLAGS=-c
#a*b + c
all: product sum
	printf "#!/bin/sh\n./$(TARGET)_x a.txt b.txt\n./$(TARGET)_p x.txt c.txt\nrm x.txt\n" > run.sh & chmod +x run.sh
product: mult_x.o
	$(CXX) mult_x.o -o $(TARGET)_x

mult_x.o: mult.cpp
	$(CXX) $(CFLAGS) -DOFILE=\"x.txt\" mult.cpp -o mult_x.o

sum: mult_p.o
	$(CXX) mult_p.o -o $(TARGET)_p

mult_p.o: mult.cpp
	$(CXX) $(CFLAGS) -DOPERATION_PLUS -DOFILE=\"out.txt\" mult.cpp -o mult_p.o

clean:
	rm -f *.o $(TARGET)_p $(TARGET)_x run.sh out.txt
