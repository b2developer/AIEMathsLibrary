#pragma once
#include "BaseMatrix.h"

MAT_T
class Matrix4 : public BaseMatrix<T>
{
public:
	Matrix4() : BaseMatrix<T>(4, 4) {};
	~Matrix4() {};
};