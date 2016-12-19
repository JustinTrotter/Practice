// Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?
//
// 1) consider if ASCII or Unicode is used.
// 2) immediately return false if string length exceeds total number of unique characters
//      ASCII has 128 unique printable characters
//      Extended ASCII has 256
//      Unicode has over a million printable characters

#include <iostream>
#include <string>
using namespace std;

bool isUniqueChars (string);
bool isUniqueCharsBitShift (string);

int main(){
        string input;
        cout << "Enter string: ";
        cin >> input;
        cout << "isUniqueChars = " << isUniqueChars(input) << endl;
        return 0;
}

bool isUniqueChars (string str) {
        if (str.length() > 128) { return false; }

        bool * charSet = new bool[128];
        for (int i = 0; i < str.length(); i++){
                if (charSet[str.at(i)]){
                        return false;
                }
                charSet[str.at(i)] = true;
        }
        delete charSet;
        return true;
}

// Assume that lowercase characters are used
bool isUniqueCharsBitShift (string str) {
        if (str.length() > 128) { return false; }

        int checker = 0;
        for (int i = 0; i < str.length(); i++){
                int val = str.at(i) - 'a';
                if ((checker & (1 << val)) > 0) {
                        return false;
                }
                checker |= (1 << val);
        }
        return true;
}
