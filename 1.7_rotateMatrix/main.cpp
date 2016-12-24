// Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes,
// write a method to rotate the image by 90 degrees.

#include <iostream>
using namespace std;

void rotate (int [3][3], int);
void printMatrix (int [3][3], int);

int main(){
	int matrix [3][3] = {{1,1,1},{0,0,2},{1,1,1}};
	cout << "original matrix:" << endl;
	printMatrix(matrix, 3);
	rotate(matrix, 3);
	cout << endl;
	printMatrix(matrix, 3);
        return 0;
}

void rotate (int matrix[3][3], int n) {
	if (n == 0) { return; }

	for (int layer = 0; layer < n / 2; layer++) {
		int first = layer;
		int last = n - 1 - layer;
		for (int i = first; i < last; i++) {
			int offset = i - first;
			int top = matrix[first][i];

			// left -> top
			matrix [first][i] = matrix[last - offset][first];

			// bottom -> left
			matrix[last - offset][first] = matrix[last][last - offset];

			// right -> bottom
			matrix[last][last - offset] = matrix[i][last];

			// top -> right
			matrix[i][last] = top;
		}
	}	
}

void printMatrix (int matrix[3][3], int n){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cout << matrix[j][i];
		}
		cout << endl;
	}
}
