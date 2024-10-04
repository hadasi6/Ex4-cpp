#include "autotest_utils.h"

/***
 * check the argmax func of a matrix, print and compare with diff
 */
int check_argmax()
{
    Matrix M1 = get_ordered_matrix(4, 3);

    const int max = 11;

    std::cout << "testing argmax " << max << " == " << M1.argmax() << std::endl;

    if(max != M1.argmax())
    {
        return 1;
    }

    M1(2, 1) = 100000.0;

    const int max2 = 7;

    std::cout << "testing argmax " << max2 << " == " << M1.argmax() << std::endl;

    if(max2 != M1.argmax())
    {
        return 1;
    }
    return 0;
}

int main()
{
    return check_argmax();
}