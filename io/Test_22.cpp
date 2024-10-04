#include <iostream>
#include "Matrix.h"

/**
 * Check if there was an exception thrown
 * @return 0 - success
 *         1, 2 - failure
 */
int main()
{

    Matrix M = Matrix(3, 3);

    //bad indexing
    std::cout << "Checking index over limit" << std::endl;
    try
    {
        std::cout << M(5, 5) << std::endl;
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