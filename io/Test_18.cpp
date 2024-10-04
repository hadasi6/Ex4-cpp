#include "autotest_utils.h"
#include <sstream>

/***
 * Check failure of friend operator >> in Matrix (Matrix read)
 */
int check_matrix_read_bad()
{
    std::cout << "checking matrix bad reading" << std::endl;
    Matrix M1(2, 3);

    float data[] = {2, 3, 4, 5};

    std::stringstream s;
    s.write((char *) data, sizeof(data));
    // should not succeed. s has 4 elements and the matrix has 6 (2x3) cells.

    try
    {
        s >> M1;
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

    M1.plain_print();

    std::cout << "nothing thrown" << std::endl;

    return 2;
}

int main()
{
    return check_matrix_read_bad();
}