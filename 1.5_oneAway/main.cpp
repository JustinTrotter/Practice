// There are three types of edits that can be performed on strings: insert a character,
// remove a character, or replace a character. Given two strings, write a function to check if they are
// one edit (or zero edits) away.

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool oneAway (string, string);

int main(){
	string str1, str2;
	cout << "Enter First String: " << endl;
	cin >> str1;
	cout << "Enter Second String: " << endl;
	cin >> str2;
	cout << "oneAway = " << oneAway(str1, str2) << endl;
        return 0;
}

bool oneAway (string str1, string str2) {
	// check lengths first
	if (abs(str1.length() - str2.length()) > 1) { return false; }

	// get shorter and longer string
	string s1 = str1.length() < str2.length() ? str1 : str2;
	string s2 = str1.length() < str2.length() ? str2 : str1;

	int index1 = 0;
	int index2 = 0;

	bool foundDifference = false;

	while (index2 < s2.length() && index1 < s1.length()) {
		if (s1.at(index1) != s2.at(index2)) {
			// ensure that this is first difference found
			if (foundDifference) { return false; }

			// note difference
			foundDifference = true;

			if (s1.length() == s2.length()) {
				// on replace, move shorter pointer
				index1++;
			}
		} else {
			// if matching, move shorter pointer
			index1++;
		}
		// always move pointer for longer string
		index2++;
	}
	return true;	
}
