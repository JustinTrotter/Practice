all: david

david: main.o cBasicShape.o cRectangle.o cTriangle.o
	    g++ -std=c++11 main.o cBasicShape.o cRectangle.o cTriangle.o -o david

main.o: main.cpp
	    g++ -std=c++11 -c main.cpp

cBasicShape.o: cBasicShape.cpp
	    g++ -std=c++11 -c cBasicShape.cpp

cRectangle.o: cRectangle.cpp
	    g++ -std=c++11 -c cRectangle.cpp

cTriangle.o: cTriangle.cpp
	    g++ -std=c++11 -c cTriangle.cpp

clean:
	    rm *o david
