#include "../include/solve_dlt.h"
#include <iostream>
void plu_factor(double Ab[8][9], double res[9]);

void solve_dlt(double src_4pts[4][2], double dst_4pts[4][2]) 
{

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

void plu_factor(double Ab[8][9], double res[9])
{
	
	// PLU factorization to solve DLT
	for (int k = 0; k < 8; ++k)
	{
		int max_val = Ab[k][k];
		int max_id = k;
		for (int row = k + 1; row < 8; ++row)
		{
			int val = Ab[row][k] > 0 ? Ab[row][k] : -Ab[row][k];
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
		if ((Ab[k][k] > 0 ? Ab[k][k] :-Ab[k][k]) < 1e-3)
		{
			printf("k = %d, singular = %f\n", k, Ab[k][k]);
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
