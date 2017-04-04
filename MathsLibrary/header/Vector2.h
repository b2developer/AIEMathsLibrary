#pragma once
#include "BaseMatrix.h"

MAT_T
class Vector2 : public BaseMatrix<T>
{
public:
	Vector2() : BaseMatrix<T>(1, 2) {};
	Vector2(T,T);
	~Vector2() {};
};