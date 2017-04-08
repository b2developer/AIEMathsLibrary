#pragma once
#include <math.h>

//forward decleration
class Matrix2;

/*
* Vector2
* 2D coordinate / offset structure
* 
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class Vector2
{
public:

	/*
	* Vector2()
	* default constructor
	*/
	Vector2() {};

	/*
	* Vector2()
	* argument constructor
	*
	* @param float - the x coordinate
	* @param float - the y coordinate
	*/
	Vector2(float _x, float _y) { x = _x; y = _y; };

	/*
	* Vector2()
	* default destructor
	*/
	~Vector2() {};

	/*
	* operator[]
	* subscript overload
	*
	* @param const int - the axis to access
	* @returns float& - the axis accessed
	*/
	float& operator[](const int index);

	/*
	* operator float *
	* cast to float pointer overload
	*
	* @returns float * - the address of the first item in the vector
	*/
	operator float *();

	/*
	* operator +
	* adds 2 vectors together
	*
	* @param const Vector2 - the other vector to use
	* @returns Vector2 - the sum
	*/
	Vector2 operator+(const Vector2 other);

	/*
	* operator -
	* subtracts the other vector from the first
	*
	* @param const Vector2 - the other vector to use
	* @returns Vector2 - the resultant
	*/
	Vector2 operator-(const Vector2 other);

	/*
	* operator *
	* multiplies a vector by a scalar
	*
	* @param const float scalar - the number to multiply all components by
	* @returns Vector2 - the resultant
	*/
	Vector2 operator*(const float scalar);

	/*
	* operator /
	* divdes a vector by a scalar
	*
	* @param const float scalar - the number to divde all components by
	* @returns Vector2 - the resultant
	*
	*/
	Vector2 operator/(const float scalar);

	/*
	* dot
	* calculates the dot product of two vectors
	*
	* @param const Vector2 - the other vector to use
	* @returns float - the dot product
	*/
	float dot(const Vector2 other);

	/*
	* sqrMagnitude
	* calculates the squared length of a vector
	*
	* @returns float - the squared length of the vector
	*/
	float sqrMagnitude();

	/*
	* magnitude
	* calculates the length of a vector
	*
	* @returns float - the length of the vector
	*/
	float magnitude();

	/*
	* normalise
	* scales the vector so that it's magnitude is 1
	* a vector with a magnitude of 1 is called a unit 
	*
	* @returns void
	*/
	void normalise();

	/*
	* normalise
	* creates a normalised version of a vector without
	* normalising the vector object that called
	*
	* @returns Vector2 - a normalised vector
	*/
	Vector2 normalised();

	/*
	* operator *
	* multiplies a vector by a transformation matrix
	*
	* @param Matrix2 matrix - the matrix to transform the vector with
	* @returns Vector2 - the resultant
	*/
	Vector2 operator*(Matrix2 matrix);

	float x = 0, y = 0;
};





/*
* operator *
* multiplies a vector by a scalar
*
* @param const float scalar - the number to multiply all components by
* @param const Vector2 vector - the vector to multiply
* @returns Vector2 - the resultant
*/
Vector2 operator*(const float scalar, const Vector2 vector);

/*
* operator /
* divdes a vector by a scalar
*
* @param const float scalar - the number to divde all components by
* @param const Vector2 vector - the vector to divide
* @returns Vector2 - the resultant
*/
Vector2 operator/(const float scalar, const Vector2 vector);

/*
* operator *
* multiplies a vector by a transformation matrix
*
* @param Matrix2 matrix - the matrix to transform the vector with
* @param Vector2 vector - the vector to copy and apply the transformation to
* @returns Vector2 - the resultant
*/
Vector2 operator*(Matrix2 matrix, Vector2 vector);