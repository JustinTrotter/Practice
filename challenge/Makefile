all: quiz

quiz: main.o 
	    g++ -std=c++11 main.o -o quiz

main.o: main.cpp
	    g++ -std=c++11 -c main.cpp

clean:
	    rm *o quiz
