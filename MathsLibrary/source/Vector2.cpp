#include "Vector2.h"

//subscript operator
float & Vector2::operator[](const int index)
{
	switch (index)
	{
	case 0: return x;
	case 1: return y;
	default: throw;
	} 
}

//cast to float pointer operator
Vector2::operator float*()
{
	return &x;
}

//addition operator
Vector2 Vector2::operator+(const Vector2 other)
{
	return Vector2{ x + other.x, y + other.y };
}

//subtraction operator
Vector2 Vector2::operator-(const Vector2 other)
{
	return Vector2{ x - other.x, y - other.y };
}

//multiplication operator
Vector2 Vector2::operator*(const float scalar)
{
	return Vector2{ x * scalar, y * scalar };
}

//division operator
Vector2 Vector2::operator/(const float scalar)
{
	return Vector2{ x / scalar, y / scalar };
}

//dot product
float Vector2::dot(const Vector2 other)
{
	return x * other.x + y * other.y;
}

//squared magnitude calculation
float Vector2::sqrMagnitude()
{
	return x * x + y * y;
}

//magnitude calculation
float Vector2::magnitude()
{
	return sqrtf(sqrMagnitude());
}

//normalise the vector
void Vector2::normalise()
{
	float mag = magnitude();

	x /= mag;
	y /= mag;
}

//calculate the normalised vector
Vector2 Vector2::normalised()
{
	float mag = magnitude();

	return Vector2{ x / mag, y / mag };
}





//multiplication operator (reordered)
Vector2 operator*(const float scalar, const Vector2 vector)
{
	return Vector2{ vector.x * scalar, vector.y * scalar };
}

//division operator (reordered)
Vector2 operator/(const float scalar, const Vector2 vector)
{
	return Vector2{ vector.x / scalar, vector.y / scalar };
}
