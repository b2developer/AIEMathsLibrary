#include "Vector2.h"

Vector2::Vector2(long double x, long double y) : BaseMatrix(1, 2)
{
	mat[0][0] = x;
	mat[0][1] = y;
}

Vector2::Vector2(const BaseMatrix& other) : BaseMatrix(1, 2)
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