#include <iostream>
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

#include "Matrix2.h"
#include "Matrix3.h"
#include "Matrix4.h"

int main()
{

	Vector2T<double> newVec = { 0.1123123123, 0.147256723 };

	Vector2 vec2 = { 0.1f, 0.1f };
	Vector2 vec3 = { 1.2f, 1.5f };

	Vector2 sum = vec2 + vec3;
	Vector2 diff = vec3 - vec2;

	Vector4 vec41 = { 1.0f, 2.0f, 3.0f, 4.0f };
	Vector4 vec412 = { 222,222, 222, 222 };
	Vector4 vec42 = { 1.0f, 2.0f, 3.0f, 4.0f };

	Vector4 sum4 = vec41 + vec42;

	Vector2 mult = vec2 * 2;
	mult = 2 * vec2;
	
	Vector4 *other;
	other = &vec412;

	Matrix2 mat21 = { 1.0f, 2.0f, 3.0f, 4.0f };
	Matrix2 mat22 = { 5.0f, 6.0f, 7.0f, 8.0f };

	Matrix2 mat23 = mat21 * mat22;

	mat21.identity();

	Vector3 vect = { 1.0f, 2.0f, 3.0f};
	Matrix3 transformer = { 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f};

	vect = vect * transformer;
	
	return 0;
}