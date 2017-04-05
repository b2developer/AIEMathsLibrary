#pragma once
#include <math.h>

/*
* Vector3
* 3D coordinate / offset structure
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class Vector3
{
public:

	/*
	* Vector3()
	* default constructor
	*/
	Vector3() {};

	/*
	* Vector3()
	* argument constructor
	*
	* @param float - the x coordinate
	* @param float - the y coordinate
	* @param float - the z coordinate
	*/
	Vector3(float _x, float _y, float _z) { x = _x; y = _y; z = _z; };

	/*
	* Vector3()
	* default destructor
	*/
	~Vector3() {};

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
	* @param const Vector3 - the other vector to use
	* @returns Vector3 - the sum
	*/
	Vector3 operator+(const Vector3 other);

	/*
	* operator -
	* subtracts the other vector from the first
	*
	* @param const Vector3 - the other vector to use
	* @returns Vector3 - the resultant
	*/
	Vector3 operator-(const Vector3 other);

	/*
	* operator *
	* multiplies a vector by a scalar
	*
	* @param const float scalar - the number to multiply all components by
	* @returns Vector3 - the resultant
	*/
	Vector3 operator*(const float scalar);

	/*
	* operator /
	* divdes a vector by a scalar
	*
	* @param const float scalar - the number to divde all components by
	* @returns Vector3 - the resultant
	*
	*/
	Vector3 operator/(const float scalar);

	/*
	* dot
	* calculates the dot product of two vectors
	*
	* @param const Vector3 - the other vector to use
	* @returns float - the dot product
	*/
	float dot(const Vector3 other);

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
	* @returns Vector3 - a normalised vector
	*/
	Vector3 normalised();

	/*
	* cross
	* computes a vector perpendicular to the two 
	* vectors given
	*
	* @param const Vector3 - the other vector to use
	* @returns Vector3 - the perpendicular vector
	*/
	Vector3 cross(const Vector3 other);

	float x = 0, y = 0, z = 0;
};





/*
* operator *
* multiplies a vector by a scalar
*
* @param const float scalar - the number to multiply all components by
* @param const Vector3 vector - the vector to multiply
* @returns Vector3 - the resultant
*/
Vector3 operator*(const float scalar, const Vector3 vector);

/*
* operator /
* divdes a vector by a scalar
*
* @param const float scalar - the number to divde all components by
* @param const Vector3 vector - the vector to divide
* @returns Vector3 - the resultant
*/
Vector3 operator/(const float scalar, const Vector3 vector);