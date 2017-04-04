#include "Matrix2.h"

Matrix2::Matrix2(const BaseMatrix& other) : BaseMatrix(2, 2)
{
	checkSize(other);

	for (int m = 0; m < other.M; m++)
	{
		for (int n = 0; n < other.N; n++)
		{
			mat[m][n] = other.mat[m][n];
		}
	}
}
