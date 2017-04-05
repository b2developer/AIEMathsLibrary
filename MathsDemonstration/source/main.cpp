#include <iostream>
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

#include "Matrix2.h"
#include "Matrix3.h"
#include "Matrix4.h"

int main()
{
	Vector2 vec2 = { 0.1f, 0.1f };
	Vector2 vec3 = { 1.2f, 1.5f };

	Vector2 sum = vec2 + vec3;
	Vector2 diff = vec3 - vec2;

	Vector4 vec41 = { 1.0f, 2.0f, 3.0f, 4.0f };
	Vector4 vec41222 = { 222,222, 222, 222 };
	Vector4 vec42 = { 1.0f, 2.0f, 3.0f, 4.0f };

	Vector4 sum4 = vec41 + vec42;

	Vector2 mult = vec2 * 2;
	mult = 2 * vec2;

	
	Vector4 *other;
	other = &vec41222;
	

	for (int t = 0; t < 1000; t++)
	{
		Matrix4 m4 = {};

		m4[0] = sum4;
		m4[1] = *other;
		m4[2] = Vector4(55,55,55,55);
		m4[3] = *other;

		float * a = (float *)m4;

		for (int i = 0; i < 16; i++)
		{
			std::cout << (a[i]) << ' ';

			if ((i + 1) % 4 == 0)
			{
				std::cout << '\n';
			}
		}
		
		std::cout << '\n';
	}

	return 0;
}