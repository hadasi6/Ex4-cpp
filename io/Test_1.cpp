#include "autotest_utils.h"

/***
 * Check the assignment operator for a Matrix object.
 */
int check_assignment()
{
    std::cout << "checking Matrix::operator=" << std::endl;
    Matrix M = get_ordered_matrix(4, 5), B;

    B = M;

    // checking correct new dimensions
    if(B.get_rows() != M.get_rows() || B.get_cols() != M.get_cols())
    {
        return 1;
    }

    // checking correct new values
    for(int i = 0; i < M.get_cols() * M.get_rows(); i++)
    {
        if((B[i] != M[i]))
        {
            return 2;
        }
    }

    return 0;
}

int main()
{
    return check_assignment();
}
