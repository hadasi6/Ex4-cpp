#include "autotest_utils.h"
#include <sstream>

/***
 * Check success of friend operator >> in Matrix (Matrix read)
 */
int check_matrix_read()
{
    std::cout << "checking matrix reading" << std::endl;
    Matrix M1(2, 3);

    float data[] = {2.1, 3, 4, 5.5, 6.3, 7};

    std::stringstream s;
    s.write((char *) data, sizeof(data));
    // should succeed. s has 6 elements and the matrix has 6 (2x3) cells.

    try
    {
        s >> M1;
    }
    catch(...)
    {
        std::cerr << "bad, got an exception (supposed to succeed reading)" << std::endl;
        return 1;
    }

    M1.plain_print();

    for(int i = 0; i < 6; ++i)
    {
        if(M1[i] != data[i])
        {
            return 2;
        }
    }

    return 0;
}

int main()
{
    return check_matrix_read();
}