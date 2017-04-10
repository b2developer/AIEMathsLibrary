#include "Vector2.h"
#include "Matrix2.h"

#include "Vector3.h"
#include "Vector4.h"

//all of the decimal types
template class Vector2<float>;
template class Vector2<double>;
template class Vector2<long double>;

//subscript operator
TEMPLATE
T & Vector2<T>::operator[](const int index)
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
Vector2<T>::operator T*()
{
	return &x;
}

//addition operator
TEMPLATE
Vector2<T> Vector2<T>::operator+(const Vector2<T> other)
{
	return Vector2<T>{ x + other.x, y + other.y };
}

//subtraction operator
TEMPLATE
Vector2<T> Vector2<T>::operator-(const Vector2<T> other)
{
	return Vector2<T>{ x - other.x, y - other.y };
}

//multiplication operator
TEMPLATE
Vector2<T> Vector2<T>::operator*(const T scalar)
{
	return Vector2<T>{ x * scalar, y * scalar };
}

//division operator
TEMPLATE
Vector2<T> Vector2<T>::operator/(const T scalar)
{
	return Vector2<T>{ x / scalar, y / scalar };
}

//dot product
TEMPLATE
T Vector2<T>::dot(const Vector2<T> other)
{
	return x * other.x + y * other.y;
}

//squared magnitude calculation
TEMPLATE
T Vector2<T>::sqrMagnitude()
{
	return x * x + y * y;
}

//magnitude calculation
TEMPLATE
T Vector2<T>::magnitude()
{
	return sqrtf(sqrMagnitude());
}

//normalise the vector
TEMPLATE
void Vector2<T>::normalise()
{
	T mag = magnitude();

	x /= mag;
	y /= mag;
}

//calculate the normalised vector
TEMPLATE
Vector2<T> Vector2<T>::normalised()
{
	T mag = magnitude();

	return Vector2<T>{ x / mag, y / mag };
}

//matrix transformation
TEMPLATE
Vector2<T> Vector2<T>::operator*(Matrix2 matrix)
{
	Vector2<T> product = {};

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
Vector2<T> Vector2<T>::swizzle(int o1, int o2)
{
	return Vector2<T>((*this)[o1], (*this)[o2]);
}

//3D swizzle
TEMPLATE
Vector3<T> Vector2<T>::swizzle(int o1, int o2, int o3)
{
	return Vector3((*this)[o1], (*this)[o2], (*this)[o3]);
}

//4D swizzle
TEMPLATE
Vector4<T> Vector2<T>::swizzle(int o1, int o2, int o3, int o4)
{
	return Vector4((*this)[o1], (*this)[o2], (*this)[o3], (*this)[o4]);
}





//multiplication operator (reordered)
Vector2<T> operator*(const T scalar, const Vector2<T> vector)
{
	return Vector2<T>{ vector.x * scalar, vector.y * scalar };
}

//division operator (reordered)
Vector2<T> operator/(const T scalar, const Vector2<T> vector)
{
	return Vector2<T>{ vector.x / scalar, vector.y / scalar };
}

//matrix transformation (reordered)
Vector2<T> operator*(Matrix2 matrix, Vector2<T> vector)
{
	Vector2<T> product = {};

	//a = Vector2<T> vector passed into the function
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
