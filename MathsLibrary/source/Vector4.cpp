#include "Vector4.h"
#include "Matrix4.h"

#include "Vector2.h"
#include "Vector3.h"

//all of the decimal types
template class Vector4<float>;
template class Vector4<double>;
template class Vector4<long double>;

//subscript operator
float & Vector4::operator[](const int index)
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

//cast to float pointer operator
Vector4::operator float*()
{
	return &x;
}

//addition operator
Vector4 Vector4::operator+(const Vector4 other)
{
	return Vector4{ x + other.x, y + other.y, z + other.z , w + other.w };
}

//subtraction operator
Vector4 Vector4::operator-(const Vector4 other)
{
	return Vector4{ x - other.x, y - other.y, z - other.z, w - other.w };
}

//multiplication operator
Vector4 Vector4::operator*(const float scalar)
{
	return Vector4{ x * scalar, y * scalar, z * scalar, w * scalar };
}

//division operator
Vector4 Vector4::operator/(const float scalar)
{
	return Vector4{ x / scalar, y / scalar, z * scalar, w * scalar };
}

//dot product
float Vector4::dot(const Vector4 other)
{
	return x * other.x + y * other.y + z * other.z + w * other.w;
}

//squared magnitude calculation
float Vector4::sqrMagnitude()
{
	return x * x + y * y + z * z + w * w;
}

//magnitude calculation
float Vector4::magnitude()
{
	return sqrtf(sqrMagnitude());
}

//normalise the vector
void Vector4::normalise()
{
	float mag = magnitude();

	x /= mag;
	y /= mag;
	z /= mag;
	w /= mag;
}

//calculate the normalised vector
Vector4 Vector4::normalised()
{
	float mag = magnitude();

	return Vector4{ x / mag, y / mag, z / mag, w / mag};
}

//calculate the perpendicular vector to two others
Vector4 Vector4::cross(const Vector4 other)
{
	return Vector4{ y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x, 0 };
}

//matrix transformation
Vector4 Vector4::operator*(Matrix4 matrix)
{
	Vector4 product = {};

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
Vector2 Vector4::swizzle(int o1, int o2)
{
	return Vector2((*this)[o1], (*this)[o2]);
}

//3D swizzle
Vector3 Vector4::swizzle(int o1, int o2, int o3)
{
	return Vector3((*this)[o1], (*this)[o2], (*this)[o3]);
}

//4D swizzle
Vector4 Vector4::swizzle(int o1, int o2, int o3, int o4)
{
	return Vector4((*this)[o1], (*this)[o2], (*this)[o3], (*this)[o4]);
}





//multiplication operator (reordered)
Vector4 operator*(const float scalar, const Vector4 vector)
{
	return Vector4{ vector.x * scalar, vector.y * scalar , vector.z * scalar, vector.w * scalar};
}

//division operator (reordered)
Vector4 operator/(const float scalar, const Vector4 vector)
{
	return Vector4{ vector.x / scalar, vector.y / scalar, vector.z / scalar, vector.w / scalar};
}

//matrix transformation (reordered)
Vector4 operator*(Matrix4 matrix, Vector4 vector)
{
	Vector4 product = {};

	//a = Vector4 vector passed into the function
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
