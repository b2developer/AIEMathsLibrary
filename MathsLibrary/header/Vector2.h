#pragma once
#include <math.h>

#define TEMPLATE template<typename T>

//forward decleration
TEMPLATE
class Matrix2T;

TEMPLATE
class Vector3T;

TEMPLATE
class Vector4T;

//which orientation to use when calculating the normal
enum class NormalDirection
{
	LEFT,
	RIGHT,
};

/*
* Vector2T
* template class
* 2D coordinate / offset structure
* 
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
TEMPLATE
class Vector2T
{
public:

	/*
	* Vector2T()
	* default constructor
	*/
	Vector2T() {};

	/*
	* Vector2T()
	* argument constructor
	*
	* @param T - the x coordinate
	* @param T - the y coordinate
	*/
	Vector2T(T _x, T _y) { x = _x; y = _y; };

	/*
	* Vector2T()
	* default destructor
	*/
	~Vector2T() {};

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
	* @param const Vector2T - the other vector to use
	* @returns Vector2T - the sum
	*/
	Vector2T operator+(const Vector2T other);

	/*
	* operator +=
	* adds 2 vectors together
	*
	* @param const Vector2T - the other vector to use
	* @returns void
	*/
	void operator+=(const Vector2T other);

	/*
	* operator -
	* subtracts the other vector from the first
	*
	* @param const Vector2T - the other vector to use
	* @returns Vector2T - the resultant
	*/
	Vector2T operator-(const Vector2T other);

	/*
	* operator *
	* multiplies a vector by a scalar
	*
	* @param const T scalar - the number to multiply all components by
	* @returns Vector2T - the resultant
	*/
	Vector2T operator*(const T scalar);

	/*
	* operator /
	* divdes a vector by a scalar
	*
	* @param const T scalar - the number to divde all components by
	* @returns Vector2T - the resultant
	*
	*/
	Vector2T operator/(const T scalar);

	/*
	* dot
	* calculates the dot product of two vectors
	*
	* @param const Vector2T - the other vector to use
	* @returns T - the dot product
	*/
	T dot(const Vector2T other);

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
	* @returns Vector2T<T> - a normalised vector
	*/
	Vector2T<T> normalised();

	/*
	* operator *
	* multiplies a vector by a transformation matrix
	*
	* @param Matrix2 matrix - the matrix to transform the vector with
	* @returns Vector2T<T> - the resultant
	*/
	Vector2T<T> operator*(Matrix2T<T> matrix);

	/*
	* normal
	*
	* returns the left or normal vector
	*
	* @param NormalDirection direction - which normal to calculate (LEFT by default)
	* @returns Vector2T<T> - the normal vector
	*/
	Vector2T<T> normal(NormalDirection direction = NormalDirection::LEFT);

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

	T x = 0, y = 0;
};

using Vector2 = Vector2T<float>;

/*
* operator *
* template function
* multiplies a vector by a scalar
*
* @param const float scalar - the number to multiply all components by
* @param const Vector2T<T> vector - the vector to multiply
* @returns Vector2T<T> - the resultant
*/
TEMPLATE
Vector2T<T> operator*(const float scalar, const Vector2T<T> vector);

//multiplication operator (reordered)
TEMPLATE
Vector2T<T> operator*(const float scalar, const Vector2T<T> vector)
{
	return Vector2T<T>{ vector.x * scalar, vector.y * scalar };
}



/*
* operator /
* template function
* divdes a vector by a scalar
*
* @param const float scalar - the number to divde all components by
* @param const Vector2T<T> vector - the vector to divide
* @returns Vector2T<T> - the resultant
*/
TEMPLATE
Vector2T<T> operator/(const float scalar, const Vector2T<T> vector);

//division operator (reordered)
TEMPLATE
Vector2T<T> operator/(const float scalar, const Vector2T<T> vector)
{
	return Vector2T<T>{ vector.x / scalar, vector.y / scalar };
}



/*
* operator *
* template function
* multiplies a vector by a transformation matrix
*
* @param Matrix2T<T> matrix - the matrix to transform the vector with
* @param Vector2T<T> vector - the vector to copy and apply the transformation to
* @returns Vector2T<T> - the resultant
*/
TEMPLATE
Vector2T<T> operator*(Matrix2T<T> matrix, Vector2T<T> vector);

//matrix transformation (reordered)
TEMPLATE
Vector2T<T> operator*(Matrix2T<T> matrix, Vector2T<T> vector)
{
	Vector2T<T> product = {};

	//a = Vector2T<T> vector passed into the function
	//b = Matrix2 matrix passed into the function

	//iterate across b's columns and a's rows
	for (int bn = 0; bn < 2; bn++)
	{
		//iterate across a's rows and b's columns
		for (int i = 0; i < 2; i++)
		{
			product[bn] = product[bn] + vector[i] * matrix.mat[i][bn];
		}
	}

	return product;
}
