#include "Vector3.h"

template class Vector3<float>;
template class Vector3<double>;
template class Vector3<long double>;

MAT_T
Vector3<T>::Vector3(T x, T y, T z) : BaseMatrix<T>(1, 3)
{
	mat[0][0] = x;
	mat[0][1] = y;
	mat[0][2] = z;
}