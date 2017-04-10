#pragma once
#include <math.h>

#define TEMPLATE template<typename T>

//forward decleration
TEMPLATE
class Matrix4<T>;

TEMPLATE
class Vector2<T>;

TEMPLATE
class Vector3<T>;

/*
* Vector4
* homogenous 3D coordinate / offset structure
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
TEMPLATE
class Vector4
{
public:

	float x = 0, y = 0, z = 0, w = 0;

	/*
	* Vector4()
	* default constructor
	*/
	Vector4() {};

	/*
	* Vector4()
	* argument constructor
	*
	* @param float - the x coordinate
	* @param float - the y coordinate
	* @param float - the z coordinate
	* @param float - the w coordinate
	*/
	Vector4(float _x, float _y, float _z, float _w) { x = _x; y = _y; z = _z; w = _w; };

	/*
	* Vector4()
	* default destructor
	*/
	~Vector4() {};

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
	* @param const Vector4 - the other vector to use
	* @returns Vector4 - the sum
	*/
	Vector4 operator+(const Vector4 other);

	/*
	* operator -
	* subtracts the other vector from the first
	*
	* @param const Vector4 - the other vector to use
	* @returns Vector4 - the resultant
	*/
	Vector4 operator-(const Vector4 other);

	/*
	* operator *
	* multiplies a vector by a scalar
	*
	* @param const float scalar - the number to multiply all components by
	* @returns Vector4 - the resultant
	*/
	Vector4 operator*(const float scalar);

	/*
	* operator /
	* divdes a vector by a scalar
	*
	* @param const float scalar - the number to divde all components by
	* @returns Vector4 - the resultant
	*
	*/
	Vector4 operator/(const float scalar);

	/*
	* dot
	* calculates the dot product of two vectors
	*
	* @param const Vector4 - the other vector to use
	* @returns float - the dot product
	*/
	float dot(const Vector4 other);

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
	* @returns Vector4 - a normalised vector
	*/
	Vector4 normalised();

	/*
	* cross
	* computes a vector perpendicular to the two
	* vectors given.
	* 
	* implements cross 
	*
	* @param const Vector4 - the other vector to use
	* @returns Vector4 - the perpendicular vector
	*/
	Vector4 cross(const Vector4 other);

	/*
	* operator *
	* multiplies a vector by a transformation matrix
	*
	* @param const Matrix4 matrix - the matrix to transform the vector with
	* @returns Vector4 - the resultant
	*/
	Vector4 operator*(const Matrix4 matrix);

	/*
	* swizzle
	* 2D swizzling method
	*
	* @param int - the first order index
	* @param int - the second order index
	* @return Vector2 - the new reordered vector
	*/
	Vector2 swizzle(int o1, int o2);

	/*
	* swizzle
	* 3D swizzling method
	*
	* @param int - the first order index
	* @param int - the second order index
	* @param int - the third order index
	* @return Vector3 - the new reordered vector
	*/
	Vector3 swizzle(int o1, int o2, int o3);

	/*
	* swizzle
	* 4D swizzling method
	*
	* @param int - the first order index
	* @param int - the second order index
	* @param int - the third order index
	* @param int - the fourth order index
	* @return Vector4 - the new reordered vector
	*/
	Vector4 swizzle(int o1, int o2, int o3, int o4);

};





/*
* operator *
* multiplies a vector by a scalar
*
* @param const float scalar - the number to multiply all components by
* @param const Vector4 vector - the vector to multiply
* @returns Vector4 - the resultant
*/
Vector4 operator*(const float scalar, const Vector4 vector);

/*
* operator /
* divdes a vector by a scalar
*
* @param const float scalar - the number to divde all components by
* @param const Vector4 vector - the vector to divide
* @returns Vector4 - the resultant
*/
Vector4 operator/(const float scalar, const Vector4 vector);

/*
* operator *
* multiplies a vector by a transformation matrix
*
* @param Matrix4 matrix - the matrix to transform the vector with
* @param Vector4 vector - the vector to copy and apply the transformation to
* @returns Vector4 - the resultant
*/
Vector4 operator*(Matrix4 matrix, Vector4 vector);