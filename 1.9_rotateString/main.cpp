// Assume you have a method isSubstring which checks if one word is a substring
// of another. Given two strings, s1, and s2, write code to check if s2 is a rotation of s1 using only one
// call to isSubString.

#include <iostream>
using namespace std;

bool isRotation (string, string);

int main(){

        return 0;
}

// Since I dont have the isSubstring function yet, Ill just psuedocode it for now

// s1 = xy = waterbottle
// x = wat
// y = erbottle
// s2 = yx = erbottlewat

bool isRotation (string s1, string s2) {
	int len = s1.length();
	// check that si and s2 are equal length and not empty
	if (len == s2.length() && len > 0) {
		//concat s1 and s1 with new buffer
		string s1s1 = s1 + s1;
		return isSubString(s1s1, s2);
	}
	return false;
}
