#include "Matrix.h"
#include <iostream>

/**
 * Check if there is a const version for get rows and cols, in Matrix
 * Initialize a regular matrix and a const matrix.
 * test existence of col and row functions,
 * also call on const objects to make sure the function is a const function
 * if this compiles and returns true we can pass
 * @return
 */
bool test_get_cols_rows()
{
    std::cout << "testing if there is a const version for get rows and cols" << std::endl;
    Matrix M = Matrix();
    const Matrix const_M = Matrix();
    M.get_rows();
    M.get_cols();

    // try on cols
    const_M.get_rows();
    const_M.get_cols();
    return true;
}

int main()
{
    test_get_cols_rows();
}









