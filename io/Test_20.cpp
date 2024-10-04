#include "autotest_utils.h"

/**
 * Check norm of a matrix.
 * @param A
 * @return 0 if the norm is correct, 1 otherwise
 */
int test_norm()
{
    Matrix A = get_ordered_matrix(2, 10);
    float expectedResult = 49.6991;
    std::cout << "A.norm() = " << A.norm() << std::endl;
    if(std::abs(A.norm() - expectedResult) >= 0.1)
    {
        return 1;
    } // if this is true, then norm is written correctly

    Matrix B = get_ordered_matrix(3, 5);
    float expectedResult2 = 31.8591;
    std::cout << "B.norm() = " << B.norm() << std::endl;
    if(std::abs(B.norm() - expectedResult2) >= 0.1)
    {
        return 1;
    }
    return 0;
}

int main()
{
    return test_norm();
}

