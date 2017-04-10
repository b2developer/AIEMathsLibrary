#include "Matrix3.h"

//all of the decimal types
template class Matrix3<float>;
template class Matrix3<double>;
template class Matrix3<long double>;

//default constructor
TEMPLATE
Matrix3<T>::Matrix3()
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
TEMPLATE
Matrix3<T>::Matrix3(T m11, T m12, T m13, 
				 T m21, T m22, T m23, 
				 T m31, T m32, T m33)
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
TEMPLATE
Vector3<T> & Matrix3<T>::operator[](const int index)
{
	switch (index)
	{
	case 0: return mat[0];
	case 1: return mat[1];
	case 2: return mat[2];
	default: throw;
	}
}

//cast to T pointer overload
TEMPLATE
Matrix3<T>::operator T*()
{
	return &mat[0][0];
}

//multiplication operator
TEMPLATE
Matrix3<T> Matrix3<T>::operator*(Matrix3<T> other)
{
	Matrix3<T> product = {};

	//a = Matrix3<T> that this function is running through
	//b = Matrix3<T> other passed into the function

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
TEMPLATE
void Matrix3<T>::identity()
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
TEMPLATE
void Matrix3<T>::setRotateX(T radians)
{
	identity(); //all other elements are reset
	mat[1][1] = cosf(radians);
	mat[1][2] = sinf(radians);
	mat[2][1] = -sinf(radians);
	mat[2][2] = cosf(radians);
}

//3D rotation matrix around Y (XZ affected)
TEMPLATE
void Matrix3<T>::setRotateY(T radians)
{
	identity(); //all other elements are reset
	mat[0][0] = cosf(radians);
	mat[0][2] = -sinf(radians);
	mat[2][0] = sinf(radians);
	mat[2][2] = cosf(radians);
}

//3D rotation matrix around Z (XY affected)
TEMPLATE
void Matrix3<T>::setRotateZ(T radians)
{
	identity(); //all other elements are reset
	mat[0][0] = cosf(radians);
	mat[0][1] = sinf(radians);
	mat[1][0] = -sinf(radians);
	mat[1][1] = cosf(radians);
}

