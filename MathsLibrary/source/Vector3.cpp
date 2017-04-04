#include "Vector3.h"

Vector3::Vector3(long double x, long double y, long double z) : BaseMatrix(1, 3)
{
	mat[0][0] = x;
	mat[0][1] = y;
	mat[0][2] = z;
}

Vector3::Vector3(const BaseMatrix& other) : BaseMatrix(1, 3)
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