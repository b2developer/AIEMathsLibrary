#include "Matrix3.h"

Matrix3::Matrix3(const BaseMatrix& other) : BaseMatrix(3, 3)
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
