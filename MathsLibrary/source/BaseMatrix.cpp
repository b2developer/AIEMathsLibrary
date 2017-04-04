#include "BaseMatrix.h"
#include <iomanip>

BaseMatrix::BaseMatrix(int m, int n)
{
	M = m;
	N = n;

	mat = new float*[m];

	for (int i = 0; i < m; i++)
	{
		mat[i] = new float[n];
	}
}

BaseMatrix::~BaseMatrix()
{
	for (int i = 0; i < M; i++)
	{
		delete[] mat[i];
	}

	delete[] mat;
}

std::ostream & operator<<(std::ostream & os, const BaseMatrix& bm)
{
	std::setprecision(6);

	for (int m = 0; m < bm.M; m++)
	{
		for (int n = 0; n < bm.N; n++)
		{
			os << bm.mat[m][n];

			if (n < bm.N - 1)
			{
				os << ',';
			}
		}

		if (m < bm.M - 1)
		{
			os << std::endl;
		}
	}

	return os;
}

BaseMatrix& BaseMatrix::operator+(const BaseMatrix& other)
{
	BaseMatrix* result = new BaseMatrix(M, N);

	checkSize(other);

	for (int m = 0; m < M; m++)
	{
		for (int n = 0; n < N; n++)
		{
			result->mat[m][n] = mat[m][n] + other.mat[m][n];
		}
	}

	return *result;
}

BaseMatrix& BaseMatrix::operator-(const BaseMatrix& other)
{
	BaseMatrix* result = new BaseMatrix(M, N);

	checkSize(other);

	for (int m = 0; m < M; m++)
	{
		for (int n = 0; n < N; n++)
		{
			result->mat[m][n] = mat[m][n] - other.mat[m][n];
		}
	}

	return *result;
}

void BaseMatrix::checkSize(const BaseMatrix& other)
{
	if (!(M == other.M && N == other.N))
	{
		throw;
	}
}

