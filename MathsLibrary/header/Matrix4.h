#pragma once
#include "Vector4.h"

/*
* Matrix4
* template class
* 4x4 matrix structure
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
TEMPLATE
class Matrix4
{
public:

	Vector4 mat[4]; //rows of numbers

	/*
	* Matrix4()
	* default constructor
	* fills matrix with zeroes
	*/
	Matrix4();

	/*
	* Matrix4()
	* argument constructor
	*
	* @param T - the 1st element of the 1st column
	* @param T - the 2nd element of the 1st column
	* @param T - the 3rd element of the 1st column
	* @param T - the 4th element of the 1st column
	*
	* @param T - the 1st element of the 2nd column
	* @param T - the 2nd element of the 2nd column
	* @param T - the 3rd element of the 2nd column
	* @param T - the 4th element of the 2nd column
	*
	* @param T - the 1st element of the 3rd column
	* @param T - the 2nd element of the 3rd column
	* @param T - the 3rd element of the 3rd column
	* @param T - the 4th element of the 3rd column
	*
	* @param T - the 1st element of the 4th column
	* @param T - the 2nd element of the 4th column
	* @param T - the 3rd element of the 4th column
	* @param T - the 4th element of the 4th column
	*/
	Matrix4(T m11, T m12, T m13, T m14,
			T m21, T m22, T m23, T m24,
			T m31, T m32, T m33, T m34,
			T m41, T m42, T m43, T m44);
	/*
	* Matrix4()
	* default destructor
	*/
	~Matrix4() {};

	/*
	* operator[]
	* subscript overload
	*
	* @param const int - the axis to access
	* @returns Vector4& - the axis accessed
	*/
	Vector4& operator[](const int index);

	/*
	* operator T *
	* cast to T pointer overload
	*
	* @returns T * - the address of the first item in the matrix
	*/
	operator T *();

	/*
	* operator*
	* applys matrix multiplication to two Matrix4s
	*
	* @param const Matrix4 - the other matrix to use
	* @returns Matrix4 - the product of the matrices
	*/
	Matrix4<T> operator*(const Matrix4<T> other);

	/*
	* identity
	* converts the matrix to an identity matrix
	* 1 0 0...
	* 0 1 0...
	* 0 0 1...
	* . . .
	* . . .
	*
	* returns void
	*/
	void identity();

	/*
	* setRotateX
	* generates a 3D homogeneous rotation matrix around the X axis given the amount of rotation in radians
	* https://en.wikipedia.org/wiki/Rotation_matrix
	*
	* param T - the amount of radians the matrix will represent
	* returns void
	*/
	void setRotateX(T radians);

	/*
	* setRotateY
	* generates a 3D homogeneous rotation matrix around the Y axis given the amount of rotation in radians
	* https://en.wikipedia.org/wiki/Rotation_matrix
	*
	* param T - the amount of radians the matrix will represent
	* returns void
	*/
	void setRotateY(T radians);

	/*
	* setRotateZ
	* generates a 3D homogeneous rotation matrix around the Z axis given the amount of rotation in radians
	* https://en.wikipedia.org/wiki/Rotation_matrix
	*
	* param T - the amount of radians the matrix will represent
	* returns void
	*/
	void setRotateZ(T radians);
};