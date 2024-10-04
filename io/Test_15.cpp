#include "autotest_utils.h"

/***
 * Check the sum of a matrix object, print and compare with diff
 */
int check_sum()
{
    Matrix M = get_ordered_matrix(4, 3);

    const float sum = 66.0;

    std::cout << "testing sum " << sum << " == " << M.sum() << std::endl;

    float diff = std::abs(sum - M.sum());

    if(diff > 0.1)
    { // take into account numerical errors
        return 1;
    }
    return 0;
}

int main()
{
    return check_sum();
}