all: checkPermutations

checkPermutations: main.o 
	    g++ main.o -o checkPermutations

main.o: main.cpp
	    g++ -c main.cpp

clean:
	    rm *o checkPermutations
