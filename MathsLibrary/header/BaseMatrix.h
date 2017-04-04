#pragma once

#define MAT_T template<typename T>

MAT_T
class BaseMatrix
{
public:
	BaseMatrix() {};
	BaseMatrix(int, int);
	~BaseMatrix();

protected:
	T** mat;
	int M = 0;
	int N = 0;
};
