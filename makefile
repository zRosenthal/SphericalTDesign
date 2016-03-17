S2D: main.cpp matrix.o sphIntvPoint/*.cpp S2DController/*.cpp
	g++ -std=c++11 -I /usr/local/Cellar/boost/1.59.0/include -I /Users/zacharyrosenthal/cxsc/include -L /Users/zacharyrosenthal/cxsc/lib main.cpp  sphIntvPoint/*.cpp S2DController/*.cpp  matrix.o -lcxsc -o S2D

matrix.o: Matrix/myMatrix.h
	g++ -std=c++11 -w -c Matrix/myMatrix.h -o matrix.o

clean:
	rm -f S2D *.o
