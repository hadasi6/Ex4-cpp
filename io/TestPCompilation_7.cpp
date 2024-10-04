#include "Matrix.h"
#include "Activation.h"
#include <iostream>

/***
 * Check const parameters Activation () operator
 */
void check_activation_const_params()
{
    std::cout << "checking const parameters Activation () operator" << std::endl;
    const Matrix A = Matrix();
    // see if compiles
    activation::relu(A);
    activation::softmax(A);
}

int main()
{
    check_activation_const_params();
}
