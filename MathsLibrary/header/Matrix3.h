#pragma once
#include "BaseMatrix.h"

MAT_T
class Matrix3 : public BaseMatrix<T>
{
public:
	Matrix3() : BaseMatrix<T>(3, 3) {};
	~Matrix3() {};
};