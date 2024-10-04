#include "autotest_utils.h"

/***
 * Check activation type
 */
int check_activation_type()
{
    std::cout << "checking activation type" << std::endl;
    Matrix weights(5, 1), bias(5, 1);

    Dense d1 = Dense(weights, bias, activation::relu);
    Dense d2 = Dense(weights, bias, activation::softmax);

    if(d1.get_activation() != activation::relu || d2.get_activation() != activation::softmax)
    {
        return 1;
    }
    return 0;

}

int main()
{
    return check_activation_type();
}
