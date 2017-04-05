#include "Matrix3.h"

//default constructor
Matrix3::Matrix3()
{
	//create an identity matrix
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			mat[i][j] = i == j ? 1 : 0; //set all diagonal members to 1
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

