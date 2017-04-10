#include "Matrix2.h"

//all of the decimal types
template class Matrix2<float>;
template class Matrix2<double>;
template class Matrix2<long double>;

//default constructor
TEMPLATE
Matrix2<T>::Matrix2()
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
TEMPLATE
Matrix2<T>::Matrix2(T m11, T m12, T m21, T m22)
{
	//assign the arguments individually
	mat[0][0] = m11;
	mat[0][1] = m12;
	mat[1][0] = m21;
	mat[1][1] = m22;
}

//subscript operator
TEMPLATE
Vector2<T> & Matrix2<T>::operator[](const int index)
{
	switch (index)
	{
	case 0: return mat[0];
	case 1: return mat[1];
	default: throw;
	}
}

//cast to T pointer overload
TEMPLATE
Matrix2<T>::operator T*()
{
	return &mat[0][0];
}

//multiplication operator
TEMPLATE
Matrix2<T> Matrix2<T>::operator*(Matrix2<T> other)
{
	Matrix2<T> product = {};

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
TEMPLATE
void Matrix2<T>::identity()
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
TEMPLATE
void Matrix2<T>::setRotate(T radians)
{
	mat[0][0] = cos(radians);
	mat[0][1] = sin(radians);
	mat[1][0] = -sin(radians);
	mat[1][1] = cos(radians);
}
