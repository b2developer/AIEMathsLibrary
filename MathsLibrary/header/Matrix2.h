#pragma once
#include "BaseMatrix.h"

class Matrix2 : public BaseMatrix
{
public:
	Matrix2() : BaseMatrix(2, 2) {};
	~Matrix2() {};
	Matrix2(const BaseMatrix& other);
};