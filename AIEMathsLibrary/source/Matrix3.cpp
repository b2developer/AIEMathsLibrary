#include "Matrix3.h"

//all of the decimal types
template class Matrix3T<float>;
template class Matrix3T<double>;
template class Matrix3T<long double>;

//default constructor
TEMPLATE
Matrix3T<T>::Matrix3T()
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
Matrix3T<T>::Matrix3T(T m11, T m12, T m13, 
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
Vector3T<T> & Matrix3T<T>::operator[](const int index)
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
Matrix3T<T>::operator T*()
{
	return &mat[0][0];
}

//multiplication operator
TEMPLATE
Matrix3T<T> Matrix3T<T>::operator*(Matrix3T<T> other)
{
	Matrix3T<T> product = {};

	//a = Matrix3T<T> that this function is running through
	//b = Matrix3T<T> other passed into the function

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
void Matrix3T<T>::identity()
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
void Matrix3T<T>::setRotateX(T radians)
{
	identity(); //all other elements are reset
	mat[1][1] = (T)cos(radians);
	mat[1][2] = (T)sin(radians);
	mat[2][1] = (T)-sin(radians);
	mat[2][2] = (T)cos(radians);
}

//3D rotation matrix around Y (XZ affected)
TEMPLATE
void Matrix3T<T>::setRotateY(T radians)
{
	identity(); //all other elements are reset
	mat[0][0] = (T)cos(radians);
	mat[0][2] = (T)-sin(radians);
	mat[2][0] = (T)sin(radians);
	mat[2][2] = (T)cos(radians);
}

//3D rotation matrix around Z (XY affected)
TEMPLATE
void Matrix3T<T>::setRotateZ(T radians)
{
	identity(); //all other elements are reset
	mat[0][0] = (T)cos(radians);
	mat[0][1] = (T)sin(radians);
	mat[1][0] = (T)-sin(radians);
	mat[1][1] = (T)cos(radians);
}

//determinant from matrix
TEMPLATE
T Matrix3T<T>::determinant()
{
	/*
	* (what each letter represents in the matrix)
	* a b c
	* d e f
	* g h i
	*/

	T a = mat[0][0];
	T b = mat[0][1];
	T c = mat[0][2];

	T d = mat[1][0];
	T e = mat[1][1];
	T f = mat[1][2];

	T g = mat[2][0];
	T h = mat[2][1];
	T i = mat[2][2];

	//combining the variables
	T aei = a * i * e; 
	T bfg = b * f * g;
	T cdh = c * d * h;
	T ceg = c * e * g;
	T bdi = b * d * i;
	T afh = a * f * h;

	return aei + bfg + cdh - ceg - bdi - afh;
}

//invert the matrix
TEMPLATE
bool Matrix3T<T>::invert()
{
	T determinant = this->determinant();

	//matrices can't be inverted 
	if (determinant == 0)
	{
		return false;
	}

	T a = mat[0][0];
	T b = mat[0][1];
	T c = mat[0][2];
	T d = mat[1][0];
	T e = mat[1][1];
	T f = mat[1][2];
	T g = mat[2][0];
	T h = mat[2][1];
	T i = mat[2][2];

	//this is done to make the final inversion step lest clustered
	T A = (e * i - f * h);
	T B = -(d * i - f * g);
	T C = (d * h - e * g);
	T D = -(b * i - c * h);
	T E = (a * i - c * g);
	T F = -(a * h - b * g);
	T G = (b * f - c * e);
	T H = -(a * f - c * d);
	T I = (a * e - b * d);

	mat[0][0] = A / determinant;
	mat[0][1] = D / determinant;
	mat[0][2] = G / determinant;

	mat[1][0] = B / determinant;
	mat[1][1] = E / determinant;
	mat[1][2] = H / determinant;

	mat[2][0] = C / determinant;
	mat[2][1] = F / determinant;
	mat[2][2] = I / determinant;

	return true;
}
