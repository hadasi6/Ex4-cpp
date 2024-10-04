#include "autotest_utils.h"

/***
 * Check Softmax Activation
 */
int check_softmax()
{
    std::cout << "checking Softmax Activation" << std::endl;
    Matrix M = Matrix(4, 1);
    for(int i = 0; i < M.get_cols() * M.get_rows(); i++)
    {
        M[i] = i;
    }
    // I guess the best way to check softmax values would be to use the pretty print
    Matrix B = activation::softmax(M);
    std::cout << "checking if all values of  M after softmax are between 0 - 1" << std::endl;
    float sum = 0;
    for(int i = 0; i < M.get_cols() * M.get_rows(); i++)
    {

        if((B[i] > 1) || (B[i] < 0))
        {
            return 1;
        }
        sum += B[i];
    }
    std::cout << "checking sum of the vector adds up to 1" << std::endl;
    // this might be too risky to check?? working with floats etc..
    if((0.99 > sum) || (sum > 1.01))
    {
        return 2;
    }
    return 0;
}

int main()
{
    return check_softmax();
}
