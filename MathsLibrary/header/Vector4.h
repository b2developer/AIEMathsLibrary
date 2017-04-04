#pragma once
#include "BaseMatrix.h"

MAT_T
class Vector4 : public BaseMatrix<T>
{
public:
	Vector4() : BaseMatrix<T>(1, 4) {};
	Vector4(T, T, T, T);
	~Vector4() {};
};