#include "Matrix4.h"
#include "Matrix3.h" //determinant process relies on matrix3

//all of the decimal types
template class Matrix4T<float>;
template class Matrix4T<double>;
template class Matrix4T<long double>;

TEMPLATE
//default constructor
Matrix4T<T>::Matrix4T()
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
TEMPLATE
Matrix4T<T>::Matrix4T(T m11, T m12, T m13, T m14, 
				 T m21, T m22, T m23, T m24,
				 T m31, T m32, T m33, T m34,
				 T m41, T m42, T m43, T m44)
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
TEMPLATE
Vector4T<T> & Matrix4T<T>::operator[](const int index)
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

//cast to T pointer overload
TEMPLATE
Matrix4T<T>::operator T*()
{
	return &mat[0][0];
}


//multiplication operator
TEMPLATE
Matrix4T<T> Matrix4T<T>::operator*(Matrix4T<T> other)
{
	Matrix4T<T> product = {};

	//a = Matrix4T<T> that this function is running through
	//b = Matrix4T<T> other passed into the function

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
TEMPLATE
void Matrix4T<T>::identity()
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
TEMPLATE
void Matrix4T<T>::setRotateX(T radians)
{
	identity(); //all other elements are reset
	mat[1][1] = (T)cos(radians);
	mat[1][2] = (T)sin(radians);
	mat[2][1] = (T)-sin(radians);
	mat[2][2] = (T)cos(radians);
}

//3D homogeneous rotation matrix around Y (XZ affected)
TEMPLATE
void Matrix4T<T>::setRotateY(T radians)
{
	identity(); //all other elements are reset
	mat[0][0] = (T)cos(radians);
	mat[0][2] = (T)-sin(radians);
	mat[2][0] = (T)sin(radians);
	mat[2][2] = (T)cos(radians);
}

//3D homogeneous rotation matrix around Z (XY affected)
TEMPLATE
void Matrix4T<T>::setRotateZ(T radians)
{
	identity(); //all other elements are reset
	mat[0][0] = (T)cos(radians);
	mat[0][1] = (T)sin(radians);
	mat[1][0] = (T)-sin(radians);
	mat[1][1] = (T)cos(radians);
}

//determinant from matrix
TEMPLATE
T Matrix4T<T>::determinant()
{
	/*
	* (what each letter represents in the matrix)
	* a b c d
	* e f g h
	* i j k l
	* m n o p
	*/

	T a = mat[0][0];
	T b = mat[0][1];
	T c = mat[0][2];
	T d = mat[0][3];

	T e = mat[1][0];
	T f = mat[1][1];
	T g = mat[1][2];
	T h = mat[1][3];

	T i = mat[2][0];
	T j = mat[2][1];
	T k = mat[2][2];
	T l = mat[2][3];

	T m = mat[3][0];
	T n = mat[3][1];
	T o = mat[3][2];
	T p = mat[3][3];

	Matrix3T<T> m1 = Matrix3T<T>{ f,g,h,j,k,l,m,n,o };
	Matrix3T<T> m2 = Matrix3T<T>{ e,g,h,i,k,l,m,o,p };
	Matrix3T<T> m3 = Matrix3T<T>{ e,f,h,i,j,l,m,n,p };
	Matrix3T<T> m4 = Matrix3T<T>{ e,f,g,i,j,k,m,n,o };

	return a * m1.determinant() - b * m2.determinant() + c * m3.determinant() - d * m4.determinant();
}


