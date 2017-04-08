#include "Matrix4.h"

//default constructor
Matrix4::Matrix4()
{
	//create an empty matrix
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			mat[i][j] = 0.0f;
		}
	}
}

//argument constructor
Matrix4::Matrix4(float m11, float m12, float m13, float m14, 
				 float m21, float m22, float m23, float m24,
				 float m31, float m32, float m33, float m34,
				 float m41, float m42, float m43, float m44)
{
	//assign the arguments individually
	mat[0][0] = m11;
	mat[0][1] = m12;
	mat[0][2] = m13;
	mat[0][3] = m14;

	mat[1][0] = m21;
	mat[1][1] = m22;
	mat[1][2] = m23;
	mat[1][3] = m24;

	mat[2][0] = m31;
	mat[2][1] = m32;
	mat[2][2] = m33;
	mat[2][3] = m34;

	mat[3][0] = m41;
	mat[3][1] = m42;
	mat[3][2] = m43;
	mat[3][3] = m44;
}

//subscript operator
Vector4 & Matrix4::operator[](const int index)
{
	switch (index)
	{
	case 0: return mat[0];
	case 1: return mat[1];
	case 2: return mat[2];
	case 3: return mat[3];
	default: throw;
	}	
}

//cast to float pointer overload
Matrix4::operator float*()
{
	return &mat[0][0];
}


//multiplication operator
Matrix4 Matrix4::operator*(Matrix4 other)
{
	Matrix4 product = {};

	//a = Matrix4 that this function is running through
	//b = Matrix4 other passed into the function

	//iterate across a's rows
	for (int am = 0; am < 4; am++)
	{
		//iterate across b's columns
		for (int bn = 0; bn < 4; bn++)
		{
			//iterate across a's columns and b's rows
			for (int i = 0; i < 4; i++)
			{
				product[bn][am] = product[bn][am] + mat[i][am] * other.mat[bn][i];
			}
		}
	}

	return product;
}

//convert to identity matrix
void Matrix4::identity()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			//checks if the iterators are on a diagonal
			mat[i][j] = i == j ? 1.0f : 0.0f;
		}
	}
}

//3D homogeneous rotation matrix around X (YZ affected)
void Matrix4::setRotateX(float radians)
{
	identity(); //all other elements are reset
	mat[1][1] = cosf(radians);
	mat[1][2] = sinf(radians);
	mat[2][1] = -sinf(radians);
	mat[2][2] = cosf(radians);
}

//3D homogeneous rotation matrix around Y (XZ affected)
void Matrix4::setRotateY(float radians)
{
	identity(); //all other elements are reset
	mat[0][0] = cosf(radians);
	mat[0][2] = -sinf(radians);
	mat[2][0] = sinf(radians);
	mat[2][2] = cosf(radians);
}

//3D homogeneous rotation matrix around Z (XY affected)
void Matrix4::setRotateZ(float radians)
{
	identity(); //all other elements are reset
	mat[0][0] = cosf(radians);
	mat[0][1] = sinf(radians);
	mat[1][0] = -sinf(radians);
	mat[1][1] = cosf(radians);
}


