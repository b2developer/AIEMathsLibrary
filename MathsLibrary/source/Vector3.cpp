#include "Vector3.h"

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