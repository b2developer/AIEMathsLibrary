#pragma once
#include "Vector3.h"

/*
* Matrix3
* 3x3 matrix structure
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class Matrix3
{
public:

	/*
	* Matrix3()
	* default constructor
	* fills matrix with an identity
	*/
	Matrix3();

	/*
	* Matrix3()
	* argument constructor
	*
	* @param float - the 1st element of the 1st column
	* @param float - the 2nd element of the 1st column
	* @param float - the 3rd element of the 1st column
	*
	* @param float - the 1st element of the 2nd column
	* @param float - the 2nd element of the 2nd column
	* @param float - the 3rd element of the 2nd column
	*
	* @param float - the 1st element of the 3rd column
	* @param float - the 2nd element of the 3rd column
	* @param float - the 3rd element of the 3rd column
	*/
	Matrix3(float m11, float m12, float m13, 
		    float m21, float m22, float m23,
			float m31, float m32, float m33);

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
	* operator float *
	* cast to float pointer overload
	*
	* @returns float * - the address of the first item in the matrix
	*/
	operator float *();


	Vector3 mat[3]; //rows of numbers
};