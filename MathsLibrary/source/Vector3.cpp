#include "Vector3.h"
#include "Matrix3.h"

#include "Vector2.h"
#include "Vector4.h"

//all of the decimal types
template class Vector3T<float>;
template class Vector3T<double>;
template class Vector3T<long double>;

//subscript operator
TEMPLATE
T & Vector3T<T>::operator[](const int index)
{
	switch (index)
	{
	case 0: return x;
	case 1: return y;
	case 2: return z;
	default: throw;
	}
}

//cast to T pointer operator
TEMPLATE
Vector3T<T>::operator T*()
{
	return &x;
}

//addition operator
TEMPLATE
Vector3T<T> Vector3T<T>::operator+(const Vector3T<T> other)
{
	return Vector3T<T>{ x + other.x, y + other.y, z + other.z};
}

TEMPLATE
void Vector3T<T>::operator+=(const Vector3T<T> other)
{
	*this = Vector3T<T>{ x + other.x, y + other.y, z + other.z};
}


//subtraction operator
TEMPLATE
Vector3T<T> Vector3T<T>::operator-(const Vector3T<T> other)
{
	return Vector3T<T>{ x - other.x, y - other.y, z - other.z};
}

//multiplication operator
TEMPLATE
Vector3T<T> Vector3T<T>::operator*(const T scalar)
{
	return Vector3T<T>{ x * scalar, y * scalar, z * scalar };
}

//division operator
TEMPLATE
Vector3T<T> Vector3T<T>::operator/(const T scalar)
{
	return Vector3T<T>{ x / scalar, y / scalar, z * scalar };
}

//dot product
TEMPLATE
T Vector3T<T>::dot(const Vector3T<T> other)
{
	return x * other.x + y * other.y + z * other.z;
}

//squared magnitude calculation
TEMPLATE
T Vector3T<T>::sqrMagnitude()
{
	return x * x + y * y + z * z;
}

//magnitude calculation
TEMPLATE
T Vector3T<T>::magnitude()
{
	return (T)sqrt(sqrMagnitude());
}

//normalise the vector
TEMPLATE
void Vector3T<T>::normalise()
{
	T mag = magnitude();

	if (mag != 0)
	{
		x /= mag;
		y /= mag;
		z /= mag;
	}
}

//calculate the normalised vector
TEMPLATE
Vector3T<T> Vector3T<T>::normalised()
{
	T mag = magnitude();

	if (mag == 0)
	{
		return Vector3T<T>{};
	}
	else
	{
		return Vector3T<T>{ x / mag, y / mag, z / mag};
	}
}

//calculate the perpendicular vector to two others
TEMPLATE
Vector3T<T> Vector3T<T>::cross(const Vector3T<T> other)
{
	return Vector3T<T>{ y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x };
}

//matrix transformation
TEMPLATE
Vector3T<T> Vector3T<T>::operator*(Matrix3T<T> matrix)
{
	Vector3T<T> product = {};

	//a = Vector that this function is passing through
	//b = Matrix3 matrix passed into the function

	//iterate across b's columns and a's rows
	for (int bn = 0; bn < 3; bn++)
	{
		//iterate across a's rows and b's columns
		for (int i = 0; i < 3; i++)
		{
			product[bn] = product[bn] + (*this)[i] * matrix.mat[i][bn];
		}
	}

	return product;
}

//2D swizzle
TEMPLATE
Vector2T<T> Vector3T<T>::swizzle(int o1, int o2)
{
	return Vector2T<T>((*this)[o1], (*this)[o2]);
}

//3D swizzle
TEMPLATE
Vector3T<T> Vector3T<T>::swizzle(int o1, int o2, int o3)
{
	return Vector3T<T>((*this)[o1], (*this)[o2], (*this)[o3]);
}

//4D swizzle
TEMPLATE
Vector4T<T> Vector3T<T>::swizzle(int o1, int o2, int o3, int o4)
{
	return Vector4T<T>((*this)[o1], (*this)[o2], (*this)[o3], (*this)[o4]);
}
