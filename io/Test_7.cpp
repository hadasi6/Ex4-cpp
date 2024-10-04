#include "autotest_utils.h"

/**
 * Check += operator
 */
int check_self_addition()
{
    std::cout << "checking += operator" << std::endl;
    Matrix M = get_ordered_matrix(5, 7);
    Matrix old = M;

    // Checking same address while doing self addition
    if(!checkSameAddress(M, M += M))
    {
        std::cout << "a new matrix needlessly created" << std::endl;
        return 1;
    }

    // Checking correct values
    for(int i = 0; i < M.get_cols() * M.get_rows(); i++)
    {
        if((2 * old[i] != M[i]))
        {
            std::cout << "addition failed" << std::endl;
            return 2;
        }
    }

    // Checking accepting const reference
    using Traits = function_traits<decltype(&Matrix::operator+=)>;
    if(!std::is_same<const Matrix &, Traits::argument<1>::type>::value)
    {
        std::cout << "operator+= doesn't accept by const reference" << std::endl;
        return 3;
    }
    return 0;
}

int main()
{
    return check_self_addition();

}