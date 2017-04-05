#include "Vector4.h"

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
