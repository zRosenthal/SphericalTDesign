s2d: matrix.o main.o
	g++ --std=c++11 matrix.o main.o -o s2d

main.o: main.cpp matrix.h
	g++ -std=c++11 -w -c main.cpp
matrix.o: matrix.h
	g++ -std=c++11 -w -c matrix.cpp -I /usr/local/Cellar/boost/1.59.0/include


clean:
	rm -f *.o s2d
