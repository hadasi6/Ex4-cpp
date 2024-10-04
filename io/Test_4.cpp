#include "autotest_utils.h"

/**
 * Checking Matrix dot function.
 * If it finds that it is correct, it returns true,
 * otherwise it returns false
 * @param matrix
 * @return 0 if dot works correctly, 2 otherwise
 */
int test_dot_good_dims()
{
    std::cout << "checking Matrix dot function" << std::endl;
    Matrix m = get_ordered_matrix(2, 10);
    Matrix result = m.dot(m);
    for(int i = 0; i < m.get_cols() * m.get_rows(); ++i)
    {
        if(result[i] != m[i] * m[i])
        {
            return 1;
        }
    }
    return 0;
}

int main()
{

    return test_dot_good_dims();
}


