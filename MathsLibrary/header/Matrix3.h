#pragma once
#include "BaseMatrix.h"

class Matrix3 : public BaseMatrix
{
public:
	Matrix3() : BaseMatrix(3, 3) {};
	~Matrix3() {};
	Matrix3(const BaseMatrix& other);
};