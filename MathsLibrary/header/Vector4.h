#pragma once
#include <math.h>

#define TEMPLATE template<typename T>

//forward decleration
TEMPLATE
class Matrix4T;

TEMPLATE
class Vector2T;

TEMPLATE
class Vector3T;

/*
* Vector4T
* homogenous 3D coordinate / offset structure
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
TEMPLATE
class Vector4T
{
public:

	T x = 0, y = 0, z = 0, w = 0;

	/*
	* Vector4T()
	* default constructor
	*/
	Vector4T() {};

	/*
	* Vector4T()
	* argument constructor
	*
	* @param T - the x coordinate
	* @param T - the y coordinate
	* @param T - the z coordinate
	* @param T - the w coordinate
	*/
	Vector4T(T _x, T _y, T _z, T _w) { x = _x; y = _y; z = _z; w = _w; };

	/*
	* Vector4T()
	* default destructor
	*/
	~Vector4T() {};

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
	operator T*();

	/*
	* operator +
	* adds 2 vectors together
	*
	* @param const Vector4T - the other vector to use
	* @returns Vector4T - the sum
	*/
	Vector4T operator+(const Vector4T other);

	/*
	* operator -
	* subtracts the other vector from the first
	*
	* @param const Vector4T - the other vector to use
	* @returns Vector4T - the resultant
	*/
	Vector4T operator-(const Vector4T other);

	/*
	* operator *
	* multiplies a vector by a scalar
	*
	* @param const T scalar - the number to multiply all components by
	* @returns Vector4T - the resultant
	*/
	Vector4T operator*(const T scalar);

	/*
	* operator /
	* divdes a vector by a scalar
	*
	* @param const T scalar - the number to divde all components by
	* @returns Vector4T - the resultant
	*
	*/
	Vector4T operator/(const T scalar);

	/*
	* dot
	* calculates the dot product of two vectors
	*
	* @param const Vector4T - the other vector to use
	* @returns T - the dot product
	*/
	T dot(const Vector4T other);

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
	* @returns Vector4T - a normalised vector
	*/
	Vector4T normalised();

	/*
	* cross
	* computes a vector perpendicular to the two
	* vectors given.
	* 
	* implements cross 
	*
	* @param const Vector4T - the other vector to use
	* @returns Vector4T - the perpendicular vector
	*/
	Vector4T cross(const Vector4T other);

	/*
	* operator *
	* multiplies a vector by a transformation matrix
	*
	* @param const Matrix4T matrix - the matrix to transform the vector with
	* @returns Vector4T - the resultant
	*/
	Vector4T operator*(const Matrix4T<T> matrix);

	/*
	* swizzle
	* 2D swizzling method
	*
	* @param int - the first order index
	* @param int - the second order index
	* @return Vector2T<T> - the new reordered vector
	*/
	Vector2T<T> swizzle(int o1, int o2);

	/*
	* swizzle
	* 3D swizzling method
	*
	* @param int - the first order index
	* @param int - the second order index
	* @param int - the third order index
	* @return Vector3T<T> - the new reordered vector
	*/
	Vector3T<T> swizzle(int o1, int o2, int o3);

	/*
	* swizzle
	* 4D swizzling method
	*
	* @param int - the first order index
	* @param int - the second order index
	* @param int - the third order index
	* @param int - the fourth order index
	* @return Vector4T<T> - the new reordered vector
	*/
	Vector4T<T> swizzle(int o1, int o2, int o3, int o4);

};

using Vector4 = Vector4T<float>;

/*
* operator *
* template function
* multiplies a vector by a scalar
*
* @param const float scalar - the number to multiply all components by
* @param const Vector4T<T> vector - the vector to multiply
* @returns Vector4T<T> - the resultant
*/
TEMPLATE
Vector4T<T> operator*(const float scalar, const Vector4T<T> vector);

//multiplication operator (reordered)
TEMPLATE
Vector4T<T> operator*(const float scalar, const Vector4T<T> vector)
{
	return Vector4T<T>{ vector.x * scalar, vector.y * scalar, vector.z * scalar, vector.w * scalar};
}



/*
* operator /
* template function
* divdes a vector by a scalar
*
* @param const float scalar - the number to divde all components by
* @param const Vector4T<T> vector - the vector to divide
* @returns Vector4T<T> - the resultant
*/
TEMPLATE
Vector4T<T> operator/(const float scalar, const Vector4T<T> vector);

//division operator (reordered)
TEMPLATE
Vector4T<T> operator/(const float scalar, const Vector4T<T> vector)
{
	return Vector4T<T>{ vector.x / scalar, vector.y / scalar, vector.z / scalar, vector.w / scalar};
}



/*
* operator *
* template function
* multiplies a vector by a transformation matrix
*
* @param Matrix4T<T> matrix - the matrix to transform the vector with
* @param Vector4T<T> vector - the vector to copy and apply the transformation to
* @returns Vector4T<T> - the resultant
*/
TEMPLATE
Vector4T<T> operator*(Matrix4T<T> matrix, Vector4T<T> vector);

//matrix transformation (reordered)
TEMPLATE
Vector4T<T> operator*(Matrix4T<T> matrix, Vector4T<T> vector)
{
	Vector4T<T> product = {};

	//a = Vector4T<T> vector passed into the function
	//b = Matrix4 matrix passed into the function

	//iterate across b's columns and a's rows
	for (int bn = 0; bn < 4; bn++)
	{
		//iterate across a's rows and b's columns
		for (int i = 0; i < 4; i++)
		{
			product[bn] = product[bn] + vector[i] * matrix.mat[i][bn];
		}
	}

	return product;
}
