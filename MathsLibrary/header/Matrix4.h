#pragma once
#include "Vector4.h"

/*
* Matrix4
* 3x3 matrix structure
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class Matrix4
{
public:

	Vector4 mat[4]; //rows of numbers

	/*
	* Matrix4()
	* default constructor
	* fills matrix with an identity
	*/
	Matrix4();

	/*
	* Matrix4()
	* argument constructor
	*
	* @param float - the 1st element of the 1st column
	* @param float - the 2nd element of the 1st column
	* @param float - the 3rd element of the 1st column
	* @param float - the 4th element of the 1st column
	*
	* @param float - the 1st element of the 2nd column
	* @param float - the 2nd element of the 2nd column
	* @param float - the 3rd element of the 2nd column
	* @param float - the 4th element of the 2nd column
	*
	* @param float - the 1st element of the 3rd column
	* @param float - the 2nd element of the 3rd column
	* @param float - the 3rd element of the 3rd column
	* @param float - the 4th element of the 3rd column
	*
	* @param float - the 1st element of the 4th column
	* @param float - the 2nd element of the 4th column
	* @param float - the 3rd element of the 4th column
	* @param float - the 4th element of the 4th column
	*/
	Matrix4(float m11, float m12, float m13, float m14,
			float m21, float m22, float m23, float m24,
			float m31, float m32, float m33, float m34,
			float m41, float m42, float m43, float m44);
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
	* operator float *
	* cast to float pointer overload
	*
	* @returns float * - the address of the first item in the matrix
	*/
	operator float *();
};