#include "unittest.h"
#include <iostream>

int main() {

	if (runUnitTests() == false) {
		std::cout << "Unit test failed!" << std::endl;
		return -1;
	}
	std::cout << "All tests passed successfully." << std::endl;

	Matrix4 a = Matrix4{ 1,6,3,8, 3,7,7,6, 4,6,4,7, 5,76,4,6 };
	Matrix4 ai = a;

	ai.invert();

	Matrix4 d;

	Vector3 p = Vector3{ 10, -10, 20 };
	Vector3 t = Vector3{ -110, 15, 80 };
	Vector3 u = Vector3{ 0,1,0 };
	Vector4 f = Vector4{ 0,0,1,0};

	Matrix4 look;
	look.lookAt(p, t, u);

	f = look * f;

	Vector3 f4 = f.GetXYZ();

	float det = a.determinant();

	Matrix4 I1 = ai * a;
	Matrix4 I2 = a * ai;

	return 0;
}