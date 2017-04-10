#include "Vector2.h"
#include "Matrix2.h"

#include "Vector3.h"
#include "Vector4.h"

//all of the decimal types
template class Vector2T<float>;
template class Vector2T<double>;
template class Vector2T<long double>;

//subscript operator
TEMPLATE
T & Vector2T<T>::operator[](const int index)
{
	switch (index)
	{
	case 0: return x;
	case 1: return y;
	default: throw;
	} 
}

//cast to T pointer operator
TEMPLATE
Vector2T<T>::operator T*()
{
	return &x;
}

//addition operator
TEMPLATE
Vector2T<T> Vector2T<T>::operator+(const Vector2T<T> other)
{
	return Vector2T<T>{ x + other.x, y + other.y };
}

//subtraction operator
TEMPLATE
Vector2T<T> Vector2T<T>::operator-(const Vector2T<T> other)
{
	return Vector2T<T>{ x - other.x, y - other.y };
}

//multiplication operator
TEMPLATE
Vector2T<T> Vector2T<T>::operator*(const T scalar)
{
	return Vector2T<T>{ x * scalar, y * scalar };
}

//division operator
TEMPLATE
Vector2T<T> Vector2T<T>::operator/(const T scalar)
{
	return Vector2T<T>{ x / scalar, y / scalar };
}

//dot product
TEMPLATE
T Vector2T<T>::dot(const Vector2T<T> other)
{
	return x * other.x + y * other.y;
}

//squared magnitude calculation
TEMPLATE
T Vector2T<T>::sqrMagnitude()
{
	return x * x + y * y;
}

//magnitude calculation
TEMPLATE
T Vector2T<T>::magnitude()
{
	return (T)sqrt(sqrMagnitude());
}

//normalise the vector
TEMPLATE
void Vector2T<T>::normalise()
{
	T mag = magnitude();

	x /= mag;
	y /= mag;
}

//calculate the normalised vector
TEMPLATE
Vector2T<T> Vector2T<T>::normalised()
{
	T mag = magnitude();

	return Vector2T<T>{ x / mag, y / mag };
}

//matrix transformation
TEMPLATE
Vector2T<T> Vector2T<T>::operator*(Matrix2T<T> matrix)
{
	Vector2T<T> product = {};

	//a = Vector that this function is passing through
	//b = Matrix2 matrix passed into the function

	//iterate across b's columns and a's rows
	for (int bn = 0; bn < 2; bn++)
	{
		//iterate across a's rows and b's columns
		for (int i = 0; i < 2; i++)
		{
			product[bn] = product[bn] + (*this)[i] * matrix.mat[i][bn];
		}
	}

	return product;
}

//2D swizzle
TEMPLATE
Vector2T<T> Vector2T<T>::swizzle(int o1, int o2)
{
	return Vector2T<T>((*this)[o1], (*this)[o2]);
}

//3D swizzle
TEMPLATE
Vector3T<T> Vector2T<T>::swizzle(int o1, int o2, int o3)
{
	return Vector3T<T>((*this)[o1], (*this)[o2], (*this)[o3]);
}

//4D swizzle
TEMPLATE
Vector4T<T> Vector2T<T>::swizzle(int o1, int o2, int o3, int o4)
{
	return Vector4T<T>((*this)[o1], (*this)[o2], (*this)[o3], (*this)[o4]);
}

