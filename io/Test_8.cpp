#include "autotest_utils.h"

/**
 * Check transpose func. Should return true if the transpose method is working correctly.
 * @param matrix the matrix we want to check
 * @return 0 if transposed successfully, 1 if transposition was not correct, 2 if dimensions were
 * messed up completely.
 */
int test_transpose(const Matrix &matrix)
{
    Matrix B = matrix;
    B.transpose();
    if(B.get_cols() != matrix.get_rows() || B.get_rows() != matrix.get_cols())
    {
        return 1;
    }
    for(int i = 0; i < B.get_rows(); ++i)
    {
        for(int j = 0; j < B.get_cols(); ++j)
        {
            if(B(i, j) != matrix(j, i))
            {
                return 2;
            }
        }
    }
    return 0;
}

int main()
{
    std::cout << "checking Transpose" << std::endl;
    Matrix A = get_ordered_matrix(2, 10);
    Matrix B = get_ordered_matrix(7, 7);

    if(int res1 = test_transpose(A) != 0)
    {
        return res1;
    }
    return test_transpose(B);
}

