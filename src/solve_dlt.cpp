#include "../include/solve_dlt.h"
#include "../include/math_operation.h"
#include <iostream>

// two method:
// 1. Gauss elimination method h = inv(A) @ b, 
// 2. PLU factorization solve Ah = b


void solve_dlt_plu(double src_4pts[4][2], double dst_4pts[4][2]) 
{
	// 1. plu factorization
	double Ab[8][9];
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (j < 2) {
				Ab[i][j] = src_4pts[i][j];
			}
			else if (j == 2) {
				Ab[i][j] = 1;
			}
			else if (j <= 5) {
				Ab[i][j] = 0;
			}
			else if (j <= 7) {
				Ab[i][j] = -src_4pts[i][j-6] * dst_4pts[i][0];
			}
			else {
				Ab[i][j] = dst_4pts[i][0];
			}
		}
	}
	for (int i = 4; i < 8; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (j <= 2) {
				Ab[i][j] = 0;
			}
			else if (j < 5) {
				Ab[i][j] = src_4pts[i - 4][j - 3];
			}
			else if (j == 5) {
				Ab[i][j] = 1;
			}
			else if (j <= 7) {
				Ab[i][j] = -src_4pts[i - 4][j - 6] * dst_4pts[i - 4][1];
			}
			else {
				Ab[i][j] = dst_4pts[i - 4][1];
			}
		}
	}
	std::cout << "Ab matrix = \n";
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 9; ++j) 
		{
			std::cout << Ab[i][j] <<"    ";
		}
		std::cout << "\n";
	}
	//
	double res[9];
	plu_factor(Ab, res);
	
	for (int row = 0; row < 3; ++row) 
	{
		for (int col = 0; col < 3; ++col)
		{
			std::cout << res[row * 3 + col] << "    ";

		}
		std::cout << "\n";
	};
}
void solve_dlt_gaussian(double src_4pts[4][2], double dst_4pts[4][2]) 
{
	// intialize A, b
	double A[8][8];
	double b[8];
	for (int i = 0; i < 4; ++i) {
		b[i] = dst_4pts[i][0];
		for (int j = 0; j < 8; ++j) {
			if (j < 2) {
				A[i][j] = src_4pts[i][j];
			}
			else if (j == 2) {
				A[i][j] = 1;
			}
			else if (j <= 5) {
				A[i][j] = 0;
			}
			else if (j <= 7) {
				A[i][j] = -src_4pts[i][j - 6] * dst_4pts[i][0];
			}
		}
	}
	for (int i = 4; i < 8; ++i) {
		b[i] = dst_4pts[i - 4][1];
		for (int j = 0; j < 9; ++j) {
			if (j <= 2) {
				A[i][j] = 0;
			}
			else if (j < 5) {
				A[i][j] = src_4pts[i - 4][j - 3];
			}
			else if (j == 5) {
				A[i][j] = 1;
			}
			else if (j <= 7) {
				A[i][j] = -src_4pts[i - 4][j - 6] * dst_4pts[i - 4][1];
			}
		}
	}
	
	// cal inverse
	double invA[8][8];
	mat_inverse(A, invA);

	// h = inv(A) @ b
	double res[9];
	res[8] = 1.0;
	for (int row = 0; row < 8; ++row) {
		double sum = 0;
		for (int col = 0; col < 8; ++col) 
		{
			sum += invA[row][col] * b[col];
		}
		res[row] = sum;
	}
	for (int row = 0; row < 3; ++row)
	{
		for (int col = 0; col < 3; ++col)
		{
			std::cout << res[row * 3 + col] << "    ";
		}
		std::cout << "\n";
	};

};

