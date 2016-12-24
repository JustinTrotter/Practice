// Write an algorithm such tht if an element in an MxN matrix is 0,
// then its entire row and column are set to 0

#include <iostream>
using namespace std;

void setZero(int[3][3], int);
void printMatrix (int[3][3], int);
void nullifyRows(int[3][3], int, int);
void nullifyCols(int[3][3], int, int);

int main(){
	int matrix [3][3] = {{1,1,0},{3,2,2},{1,1,1}};
	printMatrix(matrix, 3);
	setZero(matrix, 3);
	cout << endl;
	printMatrix(matrix, 3);	
        return 0;
}

void setZero(int matrix[3][3], int n) {
	bool row[n];
	bool col[n];

	for (int i = 0; i < n; i++) {
		row[i] = false;
		col[i] = false;
	}

	// Store the row and col index with value 0
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (matrix[i][j] == 0){
				row[i] = true;
				col[i] = true;
			}
		}
	}

	// Nullify rows
	for (int i = 0; i < n; i++){
		if (row[i]) { nullifyCols(matrix, i, n); }
	}
	
	// Nullify cols
	for (int j = 0; j < n; j++){
		if (col[j]) { nullifyRows(matrix, j, n); }
	}
	
}

void nullifyRows(int matrix[3][3], int row, int n){
	for (int j = 0; j < n; j++){
		matrix[row][j] = 0;
	}
}

void nullifyCols(int matrix[3][3], int col, int n){
	for (int i = 0; i < n; i++){
		matrix[i][col] = 0;
	}
}

void printMatrix (int matrix[3][3], int n){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cout << matrix[i][j];
		}
		cout << endl;
	}
}

