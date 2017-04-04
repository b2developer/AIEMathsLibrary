#pragma once
#include "BaseMatrix.h"

class Vector2 : public BaseMatrix
{
public:
	Vector2() : BaseMatrix(1, 2) {};
	Vector2(long double, long double);
	~Vector2() {};
	Vector2(const BaseMatrix& other);
};

