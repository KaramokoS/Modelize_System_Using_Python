
// This SWIG interface file tells SWIG to generate a Python module called "matrix" and to include the header file "Matrix.h" which contains the definition of the Matrix class.

// Then you can use the SWIG command to generate the wrapper code for python


swig -python matrix.i

// This will generate a file called "matrix_wrap.cxx" which contains the wrapper code for the Matrix class.

// Finally, you can use a C++ compiler (e.g. g++) to compile the wrapper code and the Matrix class into a shared library:

g++ -fPIC -c Matrix.cpp matrix_wrap.cxx -I/usr/include/python3.x
g++ -shared Matrix.o matrix_wrap.o -o _matrix.so


