#include "Matrix4.h"

//default constructor
Matrix4::Matrix4()
{
	//create an identity matrix
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			mat[i][j] = i == j ? 1 : 0; //set all diagonal members to 1
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

