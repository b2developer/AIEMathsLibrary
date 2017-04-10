#pragma once
#include "Vector2.h"

/*
* Matrix2T
* template class
* 2x2 matrix structure
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
TEMPLATE
class Matrix2T
{
public:

	Vector2T<T> mat[2]; //rows of numbers

	/*
	* Matrix2T()
	* default constructor
	* fills matrix with zeroes
	*/
	Matrix2T();

	/*
	* Matrix2T()
	* argument constructor
	*
	* @param T - the 1st element of the 1st row
	* @param T - the 2nd element of the 1st row
	* @param T - the 1st element of the 2nd row
	* @param T - the 2nd element of the 2nd row
	*/
	Matrix2T(T m11, T m12, T m21, T m22);

	/*
	* Matrix2T()
	* default destructor
	*/
	~Matrix2T() {};

	/*
	* operator[]
	* subscript overload
	*
	* @param const int - the axis to access
	* @returns Vector2T& - the axis accessed
	*/
	Vector2T<T>& operator[](const int index);

	/*
	* operator T *
	* cast to T pointer overload
	*
	* @returns T * - the address of the first item in the matrix
	*/
	operator T *();

	/*
	* operator*
	* applys matrix multiplication to two Matrix2Ts
	*
	* @param Matrix2T - the other matrix to use
	* @returns Matrix2T - the product of the matrices
	*/
	Matrix2T<T> operator*(Matrix2T<T> other);

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
	* setRotate
	* generates a 2D rotation matrix given the amount of rotation in radians
	* https://en.wikipedia.org/wiki/Rotation_matrix
	*
	* param T - the amount of radians the matrix will represent
	* returns void
	*/
	void setRotate(T radians);
};

using Matrix2 = Matrix2T<float>;