#include "Matrix4.h"

Matrix4::Matrix4(const BaseMatrix& other) : BaseMatrix(4, 4)
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
