#include "BaseMatrix.h"

template class BaseMatrix<float>;
template class BaseMatrix<double>;
template class BaseMatrix<long double>;

MAT_T
BaseMatrix<T>::BaseMatrix(int m, int n)
{
	M = m;
	N = n;

	mat = new T*[m];

	for (int i = 0; i < m; i++)
	{
		mat[i] = new T[n];
	}
}

MAT_T
BaseMatrix<T>::~BaseMatrix()
{
	for (int i = 0; i < M; i++)
	{
		delete[] mat[i];
	}

	delete[] mat;
}