#include "autotest_utils.h"

/***
 * Check under limit in parenthesis
 */
void check_parenthesis_under_limit()
{
    Matrix M = Matrix(3, 3);

    std::cout << "Checking under limit in parenthesis" << std::endl;
    std::cout << M(-1, -1) << std::endl;
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
        check_parenthesis_under_limit();
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
