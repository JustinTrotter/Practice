// Given a string, write a function to check if it is a permutation of a palindrome.

#include <iostream>
#include <string>
using namespace std;

bool palindromeHash (string);
void buildFrequencyTable (string, int *);
bool checkMaxOneOdd (int *, int);
int getCharNumber (char);

bool palindromeBitShift (string);
int createBitVector (string);
bool checkExactlyOneBitSet (int);
int toggle (int, int);

int main(){
	string input;
	cout << "Enter string: " << endl;
	cin >> input;
	cout << "palindrome hashed output: " << palindromeHash(input) << endl;
        cout << "palindrome bitshifted output: " << palindromeBitShift(input) << endl;
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
		if (x != -1) {
			table[x]++;
		}
	}
}

// Check that no more than one character has an odd count
bool checkMaxOneOdd (int * table, int length) {
	bool oddFound = false;
	for (int i = 0; i < length; i++){
		if (table[i] % 2 == 1) {
			if (oddFound) {
				return false;
			}
			oddFound = true;
		}
	}
	return true;
}

bool palindromeBitShift (string str){
        int bitVector = createBitVector(str);
        return bitVector == 0 || checkExactlyOneBitSet(bitVector);
}

int createBitVector (string str) {
        int bitVector = 0;
        for (int i = 0; i < str.length(); i++){
                int x = str.at(i);
                bitVector = toggle(bitVector, x);       
        }
        return bitVector;
}

int toggle (int bitVector, int index) {
        if (index < 0) { return bitVector; }

        int mask = 1 << index;
        if ((bitVector & mask) == 0) {
                bitVector |= mask;
        } else {
                bitVector &= ~mask;
        }
        return bitVector;
}

bool checkExactlyOneBitSet (int bitVector) {
        return (bitVector & (bitVector - 1)) == 0;
}
