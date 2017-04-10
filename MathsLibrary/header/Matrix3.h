#pragma once
#include "Vector3.h"

/*
* Matrix3
* template class
* 3x3 matrix structure
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
TEMPLATE
class Matrix3
{
public:

	Vector3 mat[3]; //rows of numbers

	/*
	* Matrix3()
	* default constructor
	* fills matrix with zeroes
	*/
	Matrix3();

	/*
	* Matrix3()
	* argument constructor
	*
	* @param T - the 1st element of the 1st column
	* @param T - the 2nd element of the 1st column
	* @param T - the 3rd element of the 1st column
	*
	* @param T - the 1st element of the 2nd column
	* @param T - the 2nd element of the 2nd column
	* @param T - the 3rd element of the 2nd column
	*
	* @param T - the 1st element of the 3rd column
	* @param T - the 2nd element of the 3rd column
	* @param T - the 3rd element of the 3rd column
	*/
	Matrix3(T m11, T m12, T m13, 
		    T m21, T m22, T m23,
			T m31, T m32, T m33);

	/*
	* Matrix3()
	* default destructor
	*/
	~Matrix3() {};

	/*
	* operator[]
	* subscript overload
	*
	* @param const int - the axis to access
	* @returns Vector3& - the axis accessed
	*/
	Vector3& operator[](const int index);

	/*
	* operator T *
	* cast to T pointer overload
	*
	* @returns T * - the address of the first item in the matrix
	*/
	operator T *();

	/*
	* operator*
	* applys matrix multiplication to two Matrix3s
	*
	* @param const Matrix3 - the other matrix to use
	* @returns Matrix3 - the product of the matrices
	*/
	Matrix3<T> operator*(const Matrix3<T> other);

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
	* generates a 3D rotation matrix around the X axis given the amount of rotation in radians
	* https://en.wikipedia.org/wiki/Rotation_matrix
	*
	* param T - the amount of radians the matrix will represent
	* returns void
	*/
	void setRotateX(T radians);

	/*
	* setRotateY
	* generates a 3D rotation matrix around the Y axis given the amount of rotation in radians
	* https://en.wikipedia.org/wiki/Rotation_matrix
	*
	* param T - the amount of radians the matrix will represent
	* returns void
	*/
	void setRotateY(T radians);

	/*
	* setRotateZ
	* generates a 3D rotation matrix around the Z axis given the amount of rotation in radians
	* https://en.wikipedia.org/wiki/Rotation_matrix
	*
	* param T - the amount of radians the matrix will represent
	* returns void
	*/
	void setRotateZ(T radians);
};