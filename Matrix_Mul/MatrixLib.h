#pragma once

using namespace std;

class My2Matrices
{
public:
	int **mult, **trans;
	My2Matrices();
	~My2Matrices();
	void GetSize(); // Reads the size values for the matrices
	void allocateMatrices(); // Allocate the memory for the matrices
	void GetElems(); // Reads the elements of the matrices
	int** MultMatrices();
	int** transposeMatrix(int **);
	void displayMatrix(int**, bool);
private:
	int r1, c1, r2, c2; // Rows & Columns for Matrix 1 and Matrix 2
	int **a, **b; // Matrix 1, Matrix 2

	void getMatrixElems(int**, int, int);
	int** allocateMatrix(int**, int, int);
	void freeMatrix(int**, int);
};

