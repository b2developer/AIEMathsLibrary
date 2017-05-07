#include "unittest.h"
#include <iostream>

int main() {

	if (runUnitTests() == false) {
		std::cout << "Unit test failed!" << std::endl;
		return -1;
	}
	std::cout << "All tests passed successfully." << std::endl;

	std::cout << "Starting additional tests.\n";

	Vector3 up = Vector3{ 0,1,0 };

	std::cout << "Random lookAt(4x4) tests.\n";

	for (int i = 0; i < 100; i++)
	{
		Vector3 randPos = Vector3{ (float)(rand() % 100) - 50, (float)(rand() % 100) - 50, (float)(rand() % 100) - 50 };
		Vector3 randTarget = Vector3{ (float)(rand() % 100) - 50, (float)(rand() % 100) - 50, (float)(rand() % 100) - 50 };

		Matrix4 look;

		look.lookAt(randPos, randTarget, up);

		Vector3 forwards = (Vector4)Vector3{ 0,0,1 } * look;
		Vector3 correctForwards = (randTarget - randPos).normalised();

		if ((correctForwards - forwards).sqrMagnitude() > DEFAULT_TOLERANCE * DEFAULT_TOLERANCE)
		{
			std::cout << "failed a lookAt(4x4) test.";
			return 0;
		}
	}

	std::cout << "Random lookAt(3x3) tests.\n";

	for (int i = 0; i < 100; i++)
	{
		Vector3 randPos = Vector3{ (float)(rand() % 100) - 50, (float)(rand() % 100) - 50, (float)(rand() % 100) - 50 };
		Vector3 randTarget = Vector3{ (float)(rand() % 100) - 50, (float)(rand() % 100) - 50, (float)(rand() % 100) - 50 };

		Matrix3 look;

		look.lookAt(randTarget - randPos, up);

		Vector3 forwards = Vector3 { 0, 0, 1 } * look;
		Vector3 correctForwards = (randTarget - randPos).normalised();

		if ((correctForwards - forwards).sqrMagnitude() > DEFAULT_TOLERANCE * DEFAULT_TOLERANCE)
		{
			std::cout << "failed a lookAt(3x3) test.";
			return 0;
		}
	}

	std::cout << "Euler conversions (4x4).\n";

	for (int i = 0; i < 100; i++)
	{
		Vector3 randEuler = Vector3{ (float)(rand() % 100) - 50, (float)(rand() % 100) - 50, (float)(rand() % 100) - 50 };

		Matrix4 eulerMatrix;

		eulerMatrix.rotateEuler(randEuler);
		Vector3 forwards = (Vector4)Vector3{ 0, 0, 1 } * eulerMatrix;

		Vector3 conversion = eulerMatrix.getEuler();

		Matrix4 eulerMatrix2;

		eulerMatrix2.rotateEuler(conversion);
		Vector3 forwards2 = (Vector4)Vector3 { 0, 0, 1 } *eulerMatrix2;


		if ((forwards2 - forwards).sqrMagnitude() > DEFAULT_TOLERANCE * DEFAULT_TOLERANCE)
		{
			std::cout << "failed a euler conversion test.";
			return 0;
		}
	}

	std::cout << "Euler conversions (3x3).\n";

	for (int i = 0; i < 100; i++)
	{
		Vector3 randEuler = Vector3{ (float)(rand() % 100) - 50, (float)(rand() % 100) - 50, (float)(rand() % 100) - 50 };

		Matrix3 eulerMatrix;

		eulerMatrix.rotateEuler(randEuler);
		Vector3 forwards = Vector3 { 0, 0, 1 } *eulerMatrix;

		Vector3 conversion = eulerMatrix.getEuler();

		Matrix3 eulerMatrix2;

		eulerMatrix2.rotateEuler(conversion);
		Vector3 forwards2 = Vector3 { 0, 0, 1 } *eulerMatrix2;


		if ((forwards2 - forwards).sqrMagnitude() > DEFAULT_TOLERANCE * DEFAULT_TOLERANCE)
		{
			std::cout << "failed a euler conversion test.";
			return 0;
		}
	}

	std::cout << "All additional tests passed successfully.";

	return 0;
}