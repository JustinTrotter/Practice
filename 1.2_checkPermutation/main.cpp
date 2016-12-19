// Give two strings, write a function to decide if one is a permutation of the other.

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPermutationSort (string, string);
bool isPermutationCount (string, string);

int main(){
        string str1, str2;
        cout << "Enter String 1: ";
        cin >> str1;
        cout << "Enter String 2: ";
        cin >> str2;
        cout << "isPermutationSort = " << isPermutationSort(str1, str2) << endl;
        cout << "isPermutationCount = " << isPermutationCount(str1, str2) << endl;
        return 0;
}

bool isPermutationSort (string s, string t){
        if (s.length() != t.length()) { return false; }

        // sort each string
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        // compare strings
        for (int i = 0; i < s.length(); i++){
                if (s.at(i) != t.at(i)){
                        return false;
                }
        }

        return true;
}

bool isPermutationCount (string s, string t){
        if (s.length() != t.length()) { return false; }

        int * letters = new int[128];
        
        // count each unique letter in s
        for (int i = 0; i < s.length(); i++){
                int c = (int) s.at(i);
                letters[c]++;
        }

        // uncount each unique letter in t
        for (int i = 0; i < t.length(); i++){
                int c = (int) t.at(i);
                letters[c]--;

                // if count goes negative, then not permutation
                if(letters[c] < 0) {
                        delete letters;
                        return false;
                }
        }

        delete letters;
        return true;
}
