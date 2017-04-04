#include "Vector4.h"

template class Vector4<float>;
template class Vector4<double>;
template class Vector4<long double>;

MAT_T
Vector4<T>::Vector4(T x, T y, T z, T w) : BaseMatrix<T>(1, 4)
{
	mat[0][0] = x;
	mat[0][1] = y;
	mat[0][2] = z;
	mat[0][3] = w;
}