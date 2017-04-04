#pragma once
#include "BaseMatrix.h"

class Matrix4 : public BaseMatrix
{
public:
	Matrix4() : BaseMatrix(4, 4) {};
	~Matrix4() {};
	Matrix4(const BaseMatrix& other);
};