#pragma once

// factor a matrix (8 x 8) to PLU to solve Ah = b
void plu_factor(double Ab[8][9], double res[9]);

// cal the inverse of a Matrix
void mat_inverse(double A[8][8], double invA[8][8]);
