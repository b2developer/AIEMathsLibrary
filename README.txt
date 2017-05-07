AIEMathsLibrary - by Bradley Booth

Important Notes:
- the decomposition functions for the matrix assume certain conventions about the matrix
  the rotation on 3 axes is used on a matrix 3 that is assumed to only be representing rotations
  mixing rotation matrix functions with transformation matrix functions results in incorrect decompositions

Project Features:

- passes the unit test
- library provided as a static library and DLL within the same project
- debug and release builds provided for both static libraries and DLLs
- code is fully documented to professional standards

Vector Features:

- implements all minimum requirements
- holds extensions of minimum functions such as inverted division 
  (eg. vector / divisor or divisor / vector)
- includes ability to cast between vector types
- includes additional helper functions such as sqrMagnitude() and getting the perpendicular vector Normal()
- complex swizzling of vector data
- all vectors implemented as templates with all real values (float, double, long double)

Matrix Features:

- implements all minimum requirements
- implements all extended requirements such as LookAt(eye, target ,up), relative transformations
- includes matrix decomposition functions for Matrix3 and Matrix4
- implements advanced helper functions such as the determinant, inversion, identity and transpose
- all matrices implemented as templates with all real values (float, double, long double)

Unit Test Notes:
- the unit test doesn't support templates, so i bypassed it by hiding the template with using Vector3 = Vector3T<float>
  so that they can be used like regular classes