#include "autotest_utils.h"

/***
 * Check relu
 */
int check_relu()
{
    std::cout << "checking relu" << std::endl;
    Matrix M = get_ordered_matrix(13, 1);
    Matrix ans = activation::relu(M);

    // Checking no change of positives
    for(int i = 0; i < M.get_cols() * M.get_rows(); i++)
    {
        if(M[i] != ans[i])
        {
            return 1;
        }
    }

    // Check zeroing negatives
    for(int i = 0; i < M.get_cols() * M.get_rows(); i++)
    {
        M[i] = -i;
    }
    ans = activation::relu(M);
    for(int i = 0; i < M.get_cols() * M.get_rows(); i++)
    {
        if(ans[i] != 0)
        {
            return 2;
        }
    }
    return 0;
}

int main()
{
    return check_relu();
}
