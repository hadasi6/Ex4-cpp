#include "autotest_utils.h"

/***
 * Checking correct dimensions
 */
int check_copy_ctor()
{
    Matrix M = get_ordered_matrix(7, 10);
    Matrix C(M);

    std::cout << "checking correct dimensions" << std::endl;
    if(C.get_rows() != M.get_rows() || C.get_cols() != M.get_cols())
    {
        return 1;
    }

    // Checking correct values
    for(int i = 0; i < M.get_cols() * M.get_rows(); i++)
    {
        if(M[i] != C[i])
        {
            std::cerr << "Values in copy ctor are not the same" << std::endl;
            return 2;
        }

    }

    // passing Rvalue to make sure the copy ctor takes a const reference
//    using Traits = function_traits<decltype(&Matrix::Matrix>;
//    if(!std::is_same<const Matrix&, Traits::argument<1>::type>::value)
//    {
//        std::cerr << "Operator= does not accept by const reference" << std::endl;
//        exit(2);
//    }
    return 0;

}

int main()
{
    return check_copy_ctor();
}