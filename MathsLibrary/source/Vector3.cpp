#include "Vector3.h"
#include "Matrix3.h"

#include "Vector2.h"
#include "Vector4.h"

//all of the decimal types
template class Vector3<float>;
template class Vector3<double>;
template class Vector3<long double>;

//subscript operator
float & Vector3::operator[](const int index)
{
	switch (index)
	{
	case 0: return x;
	case 1: return y;
	case 2: return z;
	default: throw;
	}
}

//cast to float pointer operator
Vector3::operator float*()
{
	return &x;
}

//addition operator
Vector3 Vector3::operator+(const Vector3 other)
{
	return Vector3{ x + other.x, y + other.y, z + other.z};
}

//subtraction operator
Vector3 Vector3::operator-(const Vector3 other)
{
	return Vector3{ x - other.x, y - other.y, z - other.z};
}

//multiplication operator
Vector3 Vector3::operator*(const float scalar)
{
	return Vector3{ x * scalar, y * scalar, z * scalar };
}

//division operator
Vector3 Vector3::operator/(const float scalar)
{
	return Vector3{ x / scalar, y / scalar, z * scalar };
}

//dot product
float Vector3::dot(const Vector3 other)
{
	return x * other.x + y * other.y + z * other.z;
}

//squared magnitude calculation
float Vector3::sqrMagnitude()
{
	return x * x + y * y + z * z;
}

//magnitude calculation
float Vector3::magnitude()
{
	return sqrtf(sqrMagnitude());
}

//normalise the vector
void Vector3::normalise()
{
	float mag = magnitude();

	x /= mag;
	y /= mag;
	z /= mag;
}

//calculate the normalised vector
Vector3 Vector3::normalised()
{
	float mag = magnitude();

	return Vector3{ x / mag, y / mag, z / mag};
}

//calculate the perpendicular vector to two others
Vector3 Vector3::cross(const Vector3 other)
{
	return Vector3{ y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x };
}

//matrix transformation
Vector3 Vector3::operator*(Matrix3 matrix)
{
	Vector3 product = {};

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
Vector2 Vector3::swizzle(int o1, int o2)
{
	return Vector2((*this)[o1], (*this)[o2]);
}

//3D swizzle
Vector3 Vector3::swizzle(int o1, int o2, int o3)
{
	return Vector3((*this)[o1], (*this)[o2], (*this)[o3]);
}

//4D swizzle
Vector4 Vector3::swizzle(int o1, int o2, int o3, int o4)
{
	return Vector4((*this)[o1], (*this)[o2], (*this)[o3], (*this)[o4]);
}




//multiplication operator (reordered)
Vector3 operator*(const float scalar, const Vector3 vector)
{
	return Vector3{ vector.x * scalar, vector.y * scalar , vector.z * scalar};
}

//division operator (reordered)
Vector3 operator/(const float scalar, const Vector3 vector)
{
	return Vector3{ vector.x / scalar, vector.y / scalar, vector.z / scalar};
}

//matrix transformation (reordered)
Vector3 operator*(Matrix3 matrix, Vector3 vector)
{
	Vector3 product = {};

	//a = Vector3 vector passed into the function
	//b = Matrix3 matrix passed into the function

	//iterate across b's columns and a's rows
	for (int bn = 0; bn < 3; bn++)
	{
		//iterate across a's rows and b's columns
		for (int i = 0; i < 3; i++)
		{
			product[bn] = product[bn] + vector[i] * matrix.mat[i][bn];
		}
	}

	return product;
}
