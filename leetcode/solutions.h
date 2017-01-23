#ifndef SOLUTIONS_H
#define SOLUTIONS_H

#include <vector>
#include <string>

using namespace std;

/* 	The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
	Given two integers x and y, calculate the Hamming distance. */
int hammingDistance(int x, int y){
	int diff = x ^ y;
	int count = 0;
	while (diff){
	    count++;
	    diff &= diff - 1;
	}
	return count;
}

/*	Given a binary array, find the maximum number of consecutive 1s in this array.*/
int findMaxConsecutiveOnes(vector<int>& nums) {
	int best = 0;
	int current = 0;
	for (auto it = nums.begin(); it != nums.end(); ++it){
	    if (*it == 1){
		current++;
		if(current > best){
		    best = current;
		}
	    } else {
		current = 0;
	    }
	}
	return best;
}

/*	Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.*/
int findComplement(int num) {
	unsigned mask = ~0;
	while (num & mask) mask <<= 1;
	return ~mask & ~num;
}

/*	Write a program that outputs the string representation of numbers from 1 to n.
	But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are 
	multiples of both three and five output “FizzBuzz”.*/
vector<string> fizzBuzz(int n) {
	vector<string> result;
	for (int i = 1; i <= n; i++){
	    if (i % 3 == 0 && i % 5 == 0){
		result.push_back("FizzBuzz");
	    } else if (i % 3 == 0){
		result.push_back("Fizz");
	    } else if (i % 5 == 0){
		result.push_back("Buzz");
	    } else {
		result.push_back(to_string(i));
	    }
	}
	return result;
}

/*	Write a function that takes a string as input and returns the string reversed*/
string reverseString(string s) {
	string reverse = "";
	for (int i = s.length() - 1; i >= 0; i--){
	    reverse += s.at(i);
	}
	return reverse;
}

/*	You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are 
	connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island 
	(i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around 
	the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. 
	Determine the perimeter of the island.*/
int islandPerimeter(vector<vector<int>>& grid) {
	int count = 0;
	for(int i = 0; i < grid.size(); i++){
		for (int j = 0; j < grid[i].size(); j++){
			//check self
			if(grid[i][j] == 1){
				//check north
				if (j == 0 || grid[i][j-1] == 0) { count++;}
				//check east
				if (i == grid.size() - 1 || grid[i+1][j] == 0) { count++;}
				//check south
				if (j == grid[i].size() - 1 || grid[i][j+1] == 0) { count++;}
				//check west
				if (i == 0 || grid[i-1][j] == 0) { count++;}
			}
		}
	}
	return count;
}
#endif
