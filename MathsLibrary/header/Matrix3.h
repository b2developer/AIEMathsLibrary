#pragma once
#include "Vector3.h"
#include "dllmain.h"

/*
* Matrix3T
* template class
* 3x3 matrix structure
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
TEMPLATE
class Matrix3T
{
public:

	Vector3T<T> mat[3]; //rows of numbers

	/*
	* Matrix3T()
	* default constructor
	* fills matrix with zeroes
	*/
	MATHSLIBRARY_API Matrix3T();

	/*
	* Matrix3T()
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
	MATHSLIBRARY_API  Matrix3T(T m11, T m12, T m13,
		    T m21, T m22, T m23,
			T m31, T m32, T m33);

	/*
	* Matrix3T()
	* default destructor
	*/
	MATHSLIBRARY_API ~Matrix3T() {};

	/*
	* operator[]
	* subscript overload
	*
	* @param const int - the axis to access
	* @returns Vector3T& - the axis accessed
	*/
	MATHSLIBRARY_API Vector3T<T>& operator[](const int index);

	/*
	* operator T *
	* cast to T pointer overload
	*
	* @returns T * - the address of the first item in the matrix
	*/
	MATHSLIBRARY_API operator T *();

	/*
	* operator*
	* applys matrix multiplication to two Matrix3Ts
	*
	* @param const Matrix3T - the other matrix to use
	* @returns Matrix3T - the product of the matrices
	*/
	MATHSLIBRARY_API Matrix3T<T> operator*(const Matrix3T<T> other);

	/*
	* identity
	* converts the matrix to an identity matrix
	* 1 0 0...
	* 0 1 0...
	* 0 0 1...
	* . . .
	* . . .
	*
	* @returns void
	*/
	MATHSLIBRARY_API void identity();

	/*
	* setRotateX
	* generates a 3D rotation matrix around the X axis given the amount of rotation in radians
	* https://en.wikipedia.org/wiki/Rotation_matrix
	*
	* @param T - the amount of radians the matrix will represent
	* @returns void
	*/
	MATHSLIBRARY_API void setRotateX(T radians);

	/*
	* setRotateY
	* generates a 3D rotation matrix around the Y axis given the amount of rotation in radians
	* https://en.wikipedia.org/wiki/Rotation_matrix
	*
	* @param T - the amount of radians the matrix will represent
	* @returns void
	*/
	MATHSLIBRARY_API void setRotateY(T radians);

	/*
	* setRotateZ
	* generates a 3D rotation matrix around the Z axis given the amount of rotation in radians
	* https://en.wikipedia.org/wiki/Rotation_matrix
	*
	* @param T - the amount of radians the matrix will represent
	* @returns void
	*/
	MATHSLIBRARY_API void setRotateZ(T radians);

	/*
	* determinant
	* calcualates the determinant of the matrix
	*
	* @returns T - the determinant of the matrix
	*/
	MATHSLIBRARY_API T determinant();

	/*
	* invert
	* inverts the matrix
	* sometimes matrices aren't invertible
	*
	* @returns bool - indicating if the inversion worked or not
	*/
	MATHSLIBRARY_API bool invert();
};

using Matrix3 = Matrix3T<float>;