#include "autotest_utils.h"

/***
 * Check whether assignment operator is deep
 */
int check_assignment_deep()
{
    std::cout << "checking whether assignment operator is deep" << std::endl;
    Matrix M(4, 5), B;

    M[2] = 1;

    B = M;

    B[2] = 2;

    if(M[2] == B[2])
    {
        return 1;
    }

    return 0;
}

/**
 * @return 0 - success
 *         1 - failure
 */
int main()
{
    return check_assignment_deep();
}
