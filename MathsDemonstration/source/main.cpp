#include <iostream>
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

#include "Matrix2.h"
#include "Matrix3.h"
#include "Matrix4.h"

int main()
{
	Vector4<float>* vec = new Vector4<float>(2.2f, 5.4f, 0.0f, 12.4f);
	delete vec;
	return 0;
}