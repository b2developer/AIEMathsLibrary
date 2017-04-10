#pragma once
#include <math.h>

#define TEMPLATE template<typename T>

//forward decleration
TEMPLATE
class Matrix3<T>;
class Vector2;
class Vector4;

/*
* Vector3
* template class
* 3D coordinate / offset structure
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
TEMPLATE
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
	* @param T - the x coordinate
	* @param T - the y coordinate
	* @param T - the z coordinate
	*/
	Vector3(T _x, T _y, T _z) { x = _x; y = _y; z = _z; };

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
	* @returns T& - the axis accessed
	*/
	T& operator[](const int index);

	/*
	* operator T *
	* cast to T pointer overload
	*
	* @returns T * - the address of the first item in the vector
	*/
	operator T *();

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
	* @param const T scalar - the number to multiply all components by
	* @returns Vector3 - the resultant
	*/
	Vector3 operator*(const T scalar);

	/*
	* operator /
	* divdes a vector by a scalar
	*
	* @param const T scalar - the number to divde all components by
	* @returns Vector3 - the resultant
	*
	*/
	Vector3 operator/(const T scalar);

	/*
	* dot
	* calculates the dot product of two vectors
	*
	* @param const Vector3 - the other vector to use
	* @returns T - the dot product
	*/
	T dot(const Vector3 other);

	/*
	* sqrMagnitude
	* calculates the squared length of a vector
	*
	* @returns T - the squared length of the vector
	*/
	T sqrMagnitude();

	/*
	* magnitude
	* calculates the length of a vector
	*
	* @returns T - the length of the vector
	*/
	T magnitude();

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

	/*
	* operator *
	* multiplies a vector by a transformation matrix
	*
	* @param const Matrix3 matrix - the matrix to transform the vector with
	* @returns Vector3 - the resultant
	*/
	Vector3 operator*(const Matrix3 matrix);

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

	T x = 0, y = 0, z = 0;
};





/*
* operator *
* template function
* multiplies a vector by a scalar
*
* @param const T scalar - the number to multiply all components by
* @param const Vector3 vector - the vector to multiply
* @returns Vector3 - the resultant
*/
TEMPLATE
Vector3 operator*(const T scalar, const Vector3 vector);

/*
* operator /
* template function
* divdes a vector by a scalar
*
* @param const T scalar - the number to divde all components by
* @param const Vector3 vector - the vector to divide
* @returns Vector3 - the resultant
*/
TEMPLATE
Vector3 operator/(const T scalar, const Vector3 vector);

/*
* operator *
* template function
* multiplies a vector by a transformation matrix
*
* @param Matrix3 matrix - the matrix to transform the vector with
* @param Vector3 vector - the vector to copy and apply the transformation to
* @returns Vector3 - the resultant
*/
TEMPLATE
Vector3 operator*(Matrix3 matrix, Vector3 vector);