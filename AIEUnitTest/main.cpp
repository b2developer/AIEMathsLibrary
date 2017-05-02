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

	d.setScale(Vector3{ 5,4,2 });

	Vector3 eulerD = d.getEuler();

	d.rotateEuler(Vector3{ -0.08f,-0.58f,0.991f });

	Vector3 scaleD = d.getScale();
    eulerD = d.getEuler();

	float det = a.determinant();

	Matrix4 I1 = ai * a;
	Matrix4 I2 = a * ai;

	return 0;
}