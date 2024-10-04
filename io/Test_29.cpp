#include "autotest_utils.h"

/***
 * Check getters for Dense
 */
int check_dense_getters()
{
    Matrix bias, w;
    bias[0] = 1;
    w[0] = 3;

    // check ctor of Dense
    Dense d(w, bias, activation::relu);

    // checking getters
    std::cout << "checking getters for Dense" << std::endl;

    std::cout << (d.get_bias()[0] == 1) << std::endl;
    if(d.get_bias()[0] != 1)
    {
        return 1;
    }
    std::cout << (d.get_weights()[0] == 3) << std::endl;
    if(d.get_weights()[0] != 3)
    {
        return 2;
    }
    return 0;
}

/**
 * @return 0 - success
 *         1, 2 - failure
 */
int main()
{
    return check_dense_getters();
}
