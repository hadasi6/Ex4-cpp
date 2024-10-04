#include "autotest_utils.h"

/***
 * Checking const bracket operator
 */
int check_brackets()
{
    Matrix M = get_ordered_matrix(7, 9);
    std::cout << "checking const bracket operator" << std::endl;
    for(int i = 0; i < M.get_cols() * M.get_rows(); i++)
    {
        if(M[i] != i)
        {
            return 1;
        }
    }
    // Check non-const bracket operator
    for(int j = 0; j < M.get_cols() * M.get_rows(); j++)
    {
        try {
            M[j] = j+1;
        } catch(...){
            return 1;
        }
    }
    return 0;
}

int main()
{
    return check_brackets();
}