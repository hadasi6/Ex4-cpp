#include "autotest_utils.h"

/***
 * Check the vectorize func of a matrix object, print and compare with diff
 */
int check_vectorize()
{
    std::cout << "checking vectorize func" << std::endl;
    Matrix M = get_ordered_matrix(4, 3);
    Matrix old = M;
    M.vectorize();

    // Checking correct dimensions
    if(M.get_cols() != 1 || M.get_rows() != 12)
    {
        return 1;
    }

    // Checking same address
    if(!checkSameAddress(M, M.vectorize()))
    {
        return 2;
    }

    // Checking same values
    for(int i = 0; i < 12; i++)
    {
        if(old[i] != M[i])
        {
            return 3;
        }
    }
    return 0;
}

int main()
{
    return check_vectorize();
}
