// Matrix library file
// MyMatrix.cpp : Matrix library file
//

#include "pch.h"
#include "MatrixLib.h"
#include <iostream>
using namespace std;

My2Matrices::My2Matrices()
{
	r1 = r2 = c1 = c2 = 0;
}

My2Matrices::~My2Matrices()
{
	if (r1 > 0) {
		freeMatrix(a, r1);
		freeMatrix(mult, r1);
	}
	if (r2 > 0) freeMatrix(b, r2);
	if (c2 > 0) freeMatrix(trans, c2);
}

void My2Matrices::GetSize()
{
	cout << "Enter rows and columns for first matrix: ";
	cin >> r1 >> c1;
	cout << "Enter rows and columns for second matrix: ";
	cin >> r2 >> c2;

	// If column of first matrix in not equal to row of second matrix,
	// ask the user to enter the size of matrix again.
	while ((c1 != r2) || (r1 <= 0) || (r1 <= 0) || (c1 <= 0) || (c2 <= 0))
	{
		cout << "Error! column of first matrix not equal to row of second, and limits need to be valid numbers.";

		cout << "Enter rows and columns for first matrix: ";
		cin >> r1 >> c1;

		cout << "Enter rows and columns for second matrix: ";
		cin >> r2 >> c2;
	}

}

int** My2Matrices::allocateMatrix(int** m, int row, int col)
{
	m = new int*[row];
	for (int i = 0; i < row; ++i)
	{
		m[i] = new int[col];
		for (int j = 0; j < col; j++)
			m[i][j] = 0;
	}
	return m;
}

void My2Matrices::allocateMatrices()
{
	a = My2Matrices::allocateMatrix(a, r1, c1);
	b = My2Matrices::allocateMatrix(b, r2, c2);

	mult = My2Matrices::allocateMatrix(mult, r1, c2);
	trans = My2Matrices::allocateMatrix(trans, c2, r1);
}

void My2Matrices::freeMatrix(int** m, int lim)
{
	for (int i = 0; i < lim; ++i)
		free (m[i]);
	free (m);
}

void My2Matrices::getMatrixElems(int** mat, int row, int col)
{
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
		{
			cout << "Enter element [" << i + 1 << "," << j + 1 << "] : ";
			cin >> mat[i][j];
		}
}

void My2Matrices::GetElems()
{

	// Storing elements of first matrix.
	cout << endl << "Enter elements of matrix 1:" << endl;
	getMatrixElems(a, r1, c1);

	// Storing elements of second matrix.
	cout << endl << "Enter elements of matrix 2:" << endl;
	getMatrixElems(b, r2, c2);

}

int** My2Matrices::MultMatrices()
{
	int i, j, k;
	// Multiplying matrix a and b and storing in array mult.
	for (i = 0; i < r1; ++i)
		for (j = 0; j < c2; ++j)
			for (k = 0; k < c1; ++k)
			{
				mult[i][j] += a[i][k] * b[k][j];
			}
	return mult;
}

int** My2Matrices::transposeMatrix(int** multMat)
{
	// Finding the transpose matrix.
	for (int i = 0; i < c2; i++) {
		for (int j = 0; j < r1; j++) {
			trans[i][j] = multMat[j][i];
		}
	}
	return trans;
}

void My2Matrices::displayMatrix(int** mat, bool transpose)
{
	int rlimit = (transpose == true) ? c2 : r1;
	int climit = (transpose == true) ? r1 : c2;
	// Displaying the contents of the matrix.
	cout << endl << "Output Matrix: " << endl;
	for (int i = 0; i < rlimit; ++i)
	{
		for (int j = 0; j < climit; ++j)
			cout << " " << mat[i][j];
		cout << endl;
	}

}
