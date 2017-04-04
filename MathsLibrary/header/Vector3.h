#pragma once
#include "BaseMatrix.h"

MAT_T
class Vector3 : public BaseMatrix<T>
{
public:
	Vector3() : BaseMatrix<T>(1, 3) {};
	Vector3(T, T, T);
	~Vector3() {};
};