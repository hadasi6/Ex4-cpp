#include "Matrix.h"
#include <iostream>

/**
 * Check addition for const matrices
 */
void check_const_addition()
{
    std::cout << "checking const parameters + operator" << std::endl;
    // set up const matrix 1,1 with value of 1
    Matrix A = Matrix(1, 1);
    A[0] = 1;
    const Matrix M = A;

    // will not compile if + operator isn't const
    Matrix B = A + A;
}

int main()
{
    check_const_addition();
}
