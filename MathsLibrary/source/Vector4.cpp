#include "Vector4.h"
#include "Matrix4.h"

#include "Vector2.h"
#include "Vector3.h"

//all of the decimal types
template class Vector4T<float>;
template class Vector4T<double>;
template class Vector4T<long double>;

//subscript operator
TEMPLATE
T & Vector4T<T>::operator[](const int index)
{
	switch (index)
	{
	case 0: return x;
	case 1: return y;
	case 2: return z;
	case 3: return w;
	default: throw;
	}
}

//cast to T pointer operator
TEMPLATE
Vector4T<T>::operator T*()
{
	return &x;
}

//addition operator
TEMPLATE
Vector4T<T> Vector4T<T>::operator+(const Vector4T<T> other)
{
	return Vector4T<T>{ x + other.x, y + other.y, z + other.z , w + other.w };
}

TEMPLATE
void Vector4T<T>::operator+=(const Vector4T<T> other)
{
	*this = Vector4T<T>{ x + other.x, y + other.y, z + other.z, w + other.w };
}
//subtraction operator
TEMPLATE
Vector4T<T> Vector4T<T>::operator-(const Vector4T<T> other)
{
	return Vector4T<T>{ x - other.x, y - other.y, z - other.z, w - other.w };
}

//multiplication operator
TEMPLATE
Vector4T<T> Vector4T<T>::operator*(const T scalar)
{
	return Vector4T<T>{ x * scalar, y * scalar, z * scalar, w * scalar };
}

//division operator
TEMPLATE
Vector4T<T> Vector4T<T>::operator/(const T scalar)
{
	return Vector4T<T>{ x / scalar, y / scalar, z * scalar, w * scalar };
}

//dot product
TEMPLATE
T Vector4T<T>::dot(const Vector4T<T> other)
{
	return x * other.x + y * other.y + z * other.z + w * other.w;
}

//squared magnitude calculation
TEMPLATE
T Vector4T<T>::sqrMagnitude()
{
	return x * x + y * y + z * z + w * w;
}

//magnitude calculation
TEMPLATE
T Vector4T<T>::magnitude()
{
	return (T)sqrt(sqrMagnitude());
}

//normalise the vector
TEMPLATE
void Vector4T<T>::normalise()
{
	T mag = magnitude();

	if (mag != 0)
	{
		x /= mag;
		y /= mag;
		z /= mag;
		w /= mag;
	}
}

//calculate the normalised vector
TEMPLATE
Vector4T<T> Vector4T<T>::normalised()
{
	T mag = magnitude();

	if (mag == 0)
	{
		return Vector4T<T>{};
	}
	else
	{
		return Vector4T<T>{ x / mag, y / mag, z / mag, w / mag};
	}
}

//calculate the perpendicular vector to two others
TEMPLATE
Vector4T<T> Vector4T<T>::cross(const Vector4T<T> other)
{
	return Vector4T<T>{ y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x, 0 };
}

//matrix transformation
TEMPLATE
Vector4T<T> Vector4T<T>::operator*(Matrix4T<T> matrix)
{
	Vector4T<T> product = {};

	//a = Vector that this function is passing through
	//b = Matrix4 matrix passed into the function

	//iterate across b's columns and a's rows
	for (int bn = 0; bn < 4; bn++)
	{
		//iterate across a's rows and b's columns
		for (int i = 0; i < 4; i++)
		{
			product[bn] = product[bn] + (*this)[i] * matrix.mat[i][bn];
		}
	}

	return product;
}

//2D swizzle
TEMPLATE
Vector2T<T> Vector4T<T>::swizzle(int o1, int o2)
{
	return Vector2T<T>((*this)[o1], (*this)[o2]);
}

//3D swizzle
TEMPLATE
Vector3T<T> Vector4T<T>::swizzle(int o1, int o2, int o3)
{
	return Vector3T<T>((*this)[o1], (*this)[o2], (*this)[o3]);
}

//4D swizzle
TEMPLATE
Vector4T<T> Vector4T<T>::swizzle(int o1, int o2, int o3, int o4)
{
	return Vector4T<T>((*this)[o1], (*this)[o2], (*this)[o3], (*this)[o4]);
}

