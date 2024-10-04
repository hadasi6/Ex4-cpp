#include "autotest_utils.h"

/**
 * This test should catch an exception and return 0.
 *  If 1 was returned, then there is a mistake.
 *  2 on wrong exception
 */
void check_ctor_bad_dims()
{
    std::cout << "checking bad dims in matrix creation" << std::endl;
    // should expect to an exception
    Matrix m = Matrix(0, -1);
}

/**
 * checking if there was an exception thrown
 * @return 0 - success
 *         1, 2 - failure
 */
int main()
{

    try
    {
        check_ctor_bad_dims();
    }

    catch(const std::exception &error)
    {
        std::cout << "good, exception was thrown" << std::endl;
        return 0;
    }
    catch(...)
    {
        std::cout << "bad, non-exception thrown" << std::endl;
        return 1;
    }

    std::cout << "nothing thrown" << std::endl;

    return 2;
}