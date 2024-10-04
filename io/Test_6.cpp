#include "autotest_utils.h"

/**
 * Check result and invalid indices of parenthesis
 */
int check_parenthesis()
{
    std::cout << "checking correct values" << std::endl;
    Matrix M = get_ordered_matrix(8, 3);

    // Checking correct values
    for(int i = 0; i < M.get_rows(); i++)
    {
        for(int j = 0; j < M.get_cols(); j++)
        {
            if(M(i, j) != (i * M.get_cols()) + j)
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    return check_parenthesis();

}