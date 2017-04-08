#pragma once
#include "Vector2.h"

/*
* Matrix2
* 2x2 matrix structure
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class Matrix2
{
public:

	Vector2 mat[2]; //rows of numbers

	/*
	* Matrix2()
	* default constructor
	* fills matrix with zeroes
	*/
	Matrix2();

	/*
	* Matrix2()
	* argument constructor
	*
	* @param float - the 1st element of the 1st row
	* @param float - the 2nd element of the 1st row
	* @param float - the 1st element of the 2nd row
	* @param float - the 2nd element of the 2nd row
	*/
	Matrix2(float m11, float m12, float m21, float m22);

	/*
	* Matrix2()
	* default destructor
	*/
	~Matrix2() {};

	/*
	* operator[]
	* subscript overload
	*
	* @param const int - the axis to access
	* @returns Vector2& - the axis accessed
	*/
	Vector2& operator[](const int index);

	/*
	* operator float *
	* cast to float pointer overload
	*
	* @returns float * - the address of the first item in the matrix
	*/
	operator float *();

	/*
	* operator*
	* applys matrix multiplication to two Matrix2s
	*
	* @param Matrix2 - the other matrix to use
	* @returns Matrix2 - the product of the matrices
	*/
	Matrix2 operator*(Matrix2 other);

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
	* param float - the amount of radians the matrix will represent
	* returns void
	*/
	void setRotate(float radians);
};