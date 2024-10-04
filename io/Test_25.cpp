#include "autotest_utils.h"

/**
 * This test should catch an exception and return 0.
 *  If 1 was returned, then there is a mistake.
 *  2 on wrong exception
 */
void check_bad_dims_add()
{
    Matrix M = Matrix(3, 3);

    Matrix B = Matrix();

    std::cout << "checking bad dims for addition" << std::endl;
    // should expect an exception
    M = M + B;
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
        check_bad_dims_add();
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
