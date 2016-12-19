// Given a string, write a function to check if it is a permutation of a palindrome.

#include <iostream>
#include <string>
using namespace std;

bool palindromeHash (string);
void buildFrequencyTable (string, int *);
bool checkMaxOneOdd (int *, int);
int getCharNumber (char);

int main(){
	string input;
	cout << "Enter string: " << endl;
	cin >> input;
	cout << "palindrome hashed output: " << palindromeHash(input) << endl;
        return 0;
}

// Use hash table to count how many times each character appears.
// Then iterate through hash table and ensure that no more than
// one character has an odd count
bool palindromeHash (string str) {
	int * table = new int [26];
	buildFrequencyTable(str, table);
	return checkMaxOneOdd(table, 26);
}

int getCharNumber (char c) {
	if ('a' <= c && c <= 'z') {
		return c - 'a';
	}
	return -1;
}

// Count how many times each character appears
void buildFrequencyTable (string str, int * table) {
	for (int i = 0; i < str.length(); i++){
		int x = getCharNumber(str.at(i));
		//cout << x << endl;
		if (x != -1) {
			table[x]++;
		}
	}
}

// Check that no more than one character has an odd count
bool checkMaxOneOdd (int * table, int length) {
	bool oddFound = false;
	for (int i = 0; i < length; i++){
		cout << table[i] << endl;
		if (table[i] % 2 == 1) {
			if (oddFound) {
				return false;
			}
			oddFound = true;
		}
	}
	return true;
}
