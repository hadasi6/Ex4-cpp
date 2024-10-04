#include "Matrix.h"
#include <iostream>
#include "autotest_utils.h"

/**
 * Check if there is a const version for Matrix::argmax
 * call on const objects to make sure Dense getters are const functions
 * if this compiles and returns true we can pass
 * @return
 */
void check_const_argmax()
{
    std::cout << "testing if there is a const version for Matrix::argmax" << std::endl;
    const Matrix m = get_ordered_matrix(5, 5);
    int s = m.argmax();
    std::cout << "got m[" << s << "] = " << m[s] << std::endl;
}

int main()
{
    check_const_argmax();
}
