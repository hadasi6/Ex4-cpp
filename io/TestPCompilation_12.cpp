#include "Matrix.h"
#include <iostream>

/***
 * Check multiplications of const Matrix with scalar
 */
void check_const_float_mult()
{
    std::cout << "checking multiplications of const Matrix with scalar" << std::endl;
    // set up const matrix 1x1 with value of 1
    Matrix A = Matrix(1, 1);
    A[0] = 1;
    const Matrix M = A;

    // check operator* with const matrix
    Matrix B = Matrix();
    B = 2 * M;
    B.plain_print();

    B = M * 2;
    B.plain_print();
}

int main()
{
    check_const_float_mult();
}
