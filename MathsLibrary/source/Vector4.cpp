#include "Vector4.h"

Vector4::Vector4(long double x, long double y, long double z, long double w) : BaseMatrix(1, 4)
{
	mat[0][0] = x;
	mat[0][1] = y;
	mat[0][2] = z;
	mat[0][3] = w;
}

Vector4::Vector4(const BaseMatrix& other) : BaseMatrix(1, 4)
{
	for (int m = 0; m < other.M; m++)
	{
		for (int n = 0; n < other.N; n++)
		{
			mat[m][n] = other.mat[m][n];
		}
	}
}