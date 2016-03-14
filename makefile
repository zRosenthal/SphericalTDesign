S2D: main.cpp SIPMatrix/*.cpp sphIntvPoint/*.cpp
	g++ -std=c++11 -I /usr/local/Cellar/boost/1.59.0/include -I /Users/zacharyrosenthal/cxsc/include -L /Users/zacharyrosenthal/cxsc/lib *.cpp SIPMatrix/*.cpp sphIntvPoint/*.cpp  -lcxsc -o S2D


clean:
	rm -f S2D
