// 1.3 Write a method to replace all spaces in a string with '%20'.
// You may assume that the string has sufficient space at the end to
// hold the additional characters, and that you are given the 'true'
// length of the string.

// Start from the end and work backwards
// Two scan approach
// 1) count number of spaces, then triple it.
// 2) in reverse order, copy the string and replace the space with '%20'

#include <iostream>
#include <string>
using namespace std;

string urlify (string, int);

int main(){
	cout << "Input is 'Mr John Smith    ', 13" << endl;
	cout << "Answer = " << urlify ("Mr John Smith            ", 13) << "!" << endl;
	
        return 0;
}

string urlify (string str, int trueLength) {
	int spaceCount = 0;
	int i = 0;
	int index;
	
	// first pass, count number of spaces
	for (i = 0; i < trueLength; i++) {
		if (str.at(i) == ' ') {
			spaceCount++;
		}
	}

	// triple space count
	index = trueLength + spaceCount * 2;

	// second pass, copy and edit string backwards
	for (i = trueLength - 1; i >= 0; i--) {
		if (str.at(i) == ' '){
			str.at(index - 1) = '0';
			str.at(index - 2) = '2';
			str.at(index - 3) = '%';
			index -= 3;
		}
		else {
			str.at(index - 1) = str.at(i);
			index--;
		}
	}

	// place NUL terminators at end of string
	for (i = trueLength + spaceCount * 2; i < str.length(); i++) {
		str.at(i) = '\0';
	}
	return str;
}
