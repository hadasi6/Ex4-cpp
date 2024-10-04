#include "autotest_utils.h"

/***
 * Check bad dims for multiplication
 */
void check_bad_dims_mult()
{
    std::cout << "checking bad dims for multiplication" << std::endl;
    Matrix M = Matrix(3, 3);

    Matrix B = Matrix();

    // use a bad multiplication: makes sure there is an exception.
    M = M * B;
    M.plain_print();
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
        check_bad_dims_mult();
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