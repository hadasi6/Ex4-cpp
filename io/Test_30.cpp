#include "autotest_utils.h"

/***
 * Check multiplication with scalar operator
 */
int check_mult_with_scalar()
{
    std::cout << "checking multiplication with scalar operator" << std::endl;
    Matrix A = get_ordered_matrix(2, 2);

    Matrix B = 2 * A;
    Matrix C = A * 2;

    // Check correct dimensions
    if(B.get_rows() != 2 || B.get_cols() != 2 || C.get_rows() != 2 || C.get_cols() != 2)
    {
        return 1;
    }

    // Check correct values
    Matrix ans = Matrix(2, 2);
    ans[0] = 0;
    ans[1] = 2;
    ans[2] = 4;
    ans[3] = 6;
    for(int i = 0; i < C.get_cols() * C.get_rows(); i++)
    {
        if(C[i] != ans[i] || B[i] != ans[i])
        {
            return 2;
        }
    }
    return 0;
}

/**
 * @return 0 - success
 *         1, 2 - failure
 */
int main()
{
    return check_mult_with_scalar();
}