#include "Matrix2.h"

//default constructor
Matrix2::Matrix2()
{
	//create an identity matrix
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			mat[i][j] = i == j ? 1 : 0; //set all diagonal members to 1
		}
	}
}

//argument constructor
Matrix2::Matrix2(float m11, float m12, float m21, float m22)
{
	//assign the arguments individually
	mat[0][0] = m11;
	mat[0][1] = m12;
	mat[1][0] = m21;
	mat[1][1] = m22;
}

//subscript operator
Vector2 & Matrix2::operator[](const int index)
{
	switch (index)
	{
	case 0: return mat[0];
	case 1: return mat[1];
	default: throw;
	}
}

//cast to float pointer overload
Matrix2::operator float*()
{
	return &mat[0][0];
}
