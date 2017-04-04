#pragma once
#include "BaseMatrix.h"

class Vector3 : public BaseMatrix
{
public:
	Vector3() : BaseMatrix(1, 3) {};
	Vector3(long double, long double, long double);
	~Vector3() {};
	Vector3(const BaseMatrix& other);
};