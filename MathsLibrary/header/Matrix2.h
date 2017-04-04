#pragma once
#include "BaseMatrix.h"

MAT_T
class Matrix2 : public BaseMatrix<T>
{
public:
	Matrix2() : BaseMatrix<T>(2, 2) {};
	~Matrix2() {};
};