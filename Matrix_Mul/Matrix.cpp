// Matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "MatrixLib.h"
#include <iostream>
using namespace std;

int main()
{
	My2Matrices Mat;

	Mat.GetSize(); // Get size of the matrices
	Mat.allocateMatrices(); // Matrix allocations
	Mat.GetElems(); // Get the elements for the 2 matrices

	Mat.MultMatrices(); // Multiplying matrix a and b and storing in array mult.
	Mat.displayMatrix(Mat.mult, false); // Displaying the multiplication of two matrix.

	Mat.transposeMatrix(Mat.mult); // Finding the transpose matrix.
	Mat.displayMatrix(Mat.trans, true); // Displaying the transpose Matrix.

	return 0;
}