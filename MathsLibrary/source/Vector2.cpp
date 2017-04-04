#include "Vector2.h"

template class Vector2<float>;
template class Vector2<double>;
template class Vector2<long double>;

MAT_T
Vector2<T>::Vector2(T x, T y) : BaseMatrix<T>(1, 2)
{
	mat[0][0] = x;
	mat[0][1] = y;
}