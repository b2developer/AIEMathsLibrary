#include "Matrix2.h"

//default constructor
Matrix2::Matrix2()
{
	//create an empty matrix
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			mat[i][j] = 0.0f;
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

//multiplication operator
Matrix2 Matrix2::operator*(Matrix2 other)
{
	Matrix2 product = {};

	//a = Matrix2 that this function is running through
	//b = Matrix2 other passed into the function

	//iterate across a's rows
	for (int am = 0; am < 2; am++)
	{
		//iterate across b's columns
		for (int bn = 0; bn < 2; bn++)
		{
			//iterate across a's columns and b's rows
			for (int i = 0; i < 2; i++)
			{
				product[bn][am] = product[bn][am] + mat[i][am] * other.mat[bn][i];
			}
		}
	}

	return product;
}

//convert to identity matrix
void Matrix2::identity()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			//checks if the iterators are on a diagonal
			mat[i][j] = i == j ? 1.0f : 0.0f;
		}
	}
}

//rotation matrix
void Matrix2::setRotate(float radians)
{
	mat[0][0] = cosf(radians);
	mat[0][1] = sinf(radians);
	mat[1][0] = -sinf(radians);
	mat[1][1] = cosf(radians);
}
