#include "../include/math_operation.h"
#include <stdio.h>
#include <iostream>


void plu_factor(double Ab[8][9], double res[9])
{

	// PLU factorization to solve DLT
	for (int k = 0; k < 8; ++k)
	{
		int max_val = Ab[k][k];
		int max_id = k;
		// switch two row

		for (int row = k + 1; row < 8; ++row)
		{

			double val = (Ab[row][k] > 0 ? Ab[row][k] : -Ab[row][k]);
			if (val > max_val) {
				max_val = val;
				max_id = row;
			}
		}
		if (max_id != k) {
			for (int col = 0; col < 9; ++col) {
				double linshi = Ab[max_id][col];
				Ab[max_id][col] = Ab[k][col];
				Ab[k][col] = linshi;
			}
		}
		if ((Ab[k][k] > 0 ? Ab[k][k] : -Ab[k][k]) < 1e-3)
		{
			printf("row = %d, singular = %f\n", k, Ab[k][k]);
		}
		for (int row = k + 1; row < 8; ++row)
		{
			double proportion = Ab[row][k] / Ab[k][k];
			for (int col = 0; col < 9; ++col) {
				Ab[row][col] -= proportion * Ab[k][col];
			}
		}
	}
	std::cout << "PLU matrix = \n";

	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 9; ++j)
		{
			std::cout << Ab[i][j] << "    ";
		}
		std::cout << "\n";
	}

	for (int col = 7; col >= 0; --col)
	{
		for (int k = col + 1; k < 8; ++k)
		{
			Ab[col][8] -= Ab[col][k] * res[k];
		}
		res[col] = Ab[col][8] / Ab[col][col];
	}
	res[8] = 1;
}

void mat_inverse(double A[8][8], double invA[8][8])
{
	// initialize invA = I
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (i == j) {
				invA[i][j] = 1.0;
			}
			else {
				invA[i][j] = 0.0;
			}
		}
	}
	

	// gaussian elimination method
	for (int k = 0; k < 8; ++k)
	{
		int max_val = A[k][k];
		int max_id = k;
		// switch two row
		for (int row = k + 1; row < 8; ++row)
		{
			double val = (A[row][k] > 0 ? A[row][k] : -A[row][k]);
			if (val > max_val) {
				max_val = val;
				max_id = row;
			}
		}
		if (max_id != k) 
		{
			for (int col = 0; col < 8; ++col) 
			{
				double linshi = A[max_id][col];
				A[max_id][col] = A[k][col];
				A[k][col] = linshi;
				// 
				linshi = invA[max_id][col];
				invA[max_id][col] = invA[k][col];
				invA[k][col] = linshi;
			}
		}
		
		double pivot = A[k][k];
		for (int col = 0; col < 8; ++col) 
		{
			A[k][col] /= pivot;
			invA[k][col] /= pivot;
		}

		for (int row = 0; row < 8; ++row)
		{
			if (row == k) {continue;}
			double proportion = A[row][k] / A[k][k];
			for (int col = 0; col < 8; ++col) 
			{
				A[row][col] -= proportion * A[k][col];
				invA[row][col] -= proportion * invA[k][col];
			}
		}
	}
	

	std::cout << "inverse matrix = \n";

	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j)
		{
			std::cout << invA[i][j] << "    ";
		}
		std::cout << "\n";
	}
};
