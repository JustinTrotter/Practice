// Implement a method to perform a basic string compression using the counts of repeated characters.

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string compress (string);

int main(){
	string str;
	cout << "Enter string: ";
	cin >> str;
	cout << "Compressed String: " << compress(str) << endl;
        return 0;
}

string compress (string str){
	stringstream ss;
	int countConsecutive = 0;
	for (int i = 0; i < str.length(); i++) {
		countConsecutive++;
		if (i + 1 >= str.length() || str.at(i) != str.at(i + 1)) {
			ss << str.at(i);
			ss << countConsecutive;
			countConsecutive = 0;
		}
	}
	ss.seekg(0,ios::end);
	int size = ss.tellg();
	return size < str.length() ? ss.str() : str;
}
