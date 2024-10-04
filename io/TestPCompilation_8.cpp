#include "Matrix.h"
#include <iostream>

/**
 * Check if += operator has const parameters
 */
void check_const_accumalated_sum()
{
    std::cout << "checking const parameters += operator" << std::endl;
    Matrix A = Matrix(1, 1);
    A[0] = 1;
    const Matrix M = A;
    // won't compile if += doesnt keep M as const
    A += M;
}

int main()
{
    check_const_accumalated_sum();
}
