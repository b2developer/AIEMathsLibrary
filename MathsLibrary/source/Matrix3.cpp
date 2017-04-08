#include "Matrix3.h"

//default constructor
Matrix3::Matrix3()
{
	//create an empty matrix
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			mat[i][j] = 0.0f;
		}
	}
}

//argument constructor
Matrix3::Matrix3(float m11, float m12, float m13, 
				 float m21, float m22, float m23, 
				 float m31, float m32, float m33)
{
	//assign the arguments individually
	mat[0][0] = m11;
	mat[0][1] = m12;
	mat[0][2] = m13;

	mat[1][0] = m21;
	mat[1][1] = m22;
	mat[1][2] = m23;

	mat[2][0] = m31;
	mat[2][1] = m32;
	mat[2][2] = m33;
}

//subscript operator
Vector3 & Matrix3::operator[](const int index)
{
	switch (index)
	{
	case 0: return mat[0];
	case 1: return mat[1];
	case 2: return mat[2];
	default: throw;
	}
}

//cast to float pointer overload
Matrix3::operator float*()
{
	return &mat[0][0];
}

//multiplication operator
Matrix3 Matrix3::operator*(Matrix3 other)
{
	Matrix3 product = {};

	//a = Matrix3 that this function is running through
	//b = Matrix3 other passed into the function

	//iterate across a's rows
	for (int am = 0; am < 3; am++)
	{
		//iterate across b's columns
		for (int bn = 0; bn < 3; bn++)
		{
			//iterate across a's columns and b's rows
			for (int i = 0; i < 3; i++)
			{
				product[bn][am] = product[bn][am] + mat[i][am] * other.mat[bn][i];
			}
		}
	}

	return product;
}

//convert to identity matrix
void Matrix3::identity()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//checks if the iterators are on a diagonal
			mat[i][j] = i == j ? 1.0f : 0.0f;
		}
	}
}

//3D rotation matrix around X (YZ affected)
void Matrix3::setRotateX(float radians)
{
	identity(); //all other elements are reset
	mat[1][1] = cosf(radians);
	mat[1][2] = sinf(radians);
	mat[2][1] = -sinf(radians);
	mat[2][2] = cosf(radians);
}

//3D rotation matrix around Y (XZ affected)
void Matrix3::setRotateY(float radians)
{
	identity(); //all other elements are reset
	mat[0][0] = cosf(radians);
	mat[0][2] = -sinf(radians);
	mat[2][0] = sinf(radians);
	mat[2][2] = cosf(radians);
}

//3D rotation matrix around Z (XY affected)
void Matrix3::setRotateZ(float radians)
{
	identity(); //all other elements are reset
	mat[0][0] = cosf(radians);
	mat[0][1] = sinf(radians);
	mat[1][0] = -sinf(radians);
	mat[1][1] = cosf(radians);
}

