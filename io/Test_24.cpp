#include "Matrix.h"
#include "autotest_utils.h"

/**
 * This test should catch an exception and return 0.
 *  If 1 was returned, then there is a mistake.
 *  2 on wrong exception
 */
void test_dot_bad_dims()
{
    Matrix A = get_ordered_matrix(3, 3);
    Matrix B = get_ordered_matrix(3, 4);
    A.dot(B);
    A.plain_print();

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
        test_dot_bad_dims();

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
