#include <iostream>
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

#include "Matrix2.h"
#include "Matrix3.h"
#include "Matrix4.h"

int main()
{

	Vector2 vec1 = { 0.0f, 1.2f };
	Vector2 vec2 = { 1.4f, 1.0f };

	Vector2 vec3 = vec1 + vec2;

	std::cout << vec1 << std::endl;
	std::cout << vec2 << std::endl;
	std::cout << vec3 << std::endl;

	return 0;
}