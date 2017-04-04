#pragma once
#include "BaseMatrix.h"

class Vector4 : public BaseMatrix
{
public:
	Vector4() : BaseMatrix(1, 4) {};
	Vector4(long double, long double, long double, long double);
	~Vector4() {};
	Vector4(const BaseMatrix& other);
};