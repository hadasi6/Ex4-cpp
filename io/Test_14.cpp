#include "autotest_utils.h"

/**
* Check existence of Dense::operator()
*/
int check_dense_operator()
{
    Matrix m, bias, w;
    m[0] = 2;
    bias[0] = 1;
    w[0] = 3;

    // check ctor of Dense
    Dense d(w, bias, activation::relu);

    // check () operator
    Matrix D = d(m);
    std::cout << "checking dense getters and operator ()" << std::endl;
    std::cout << "checking () operator, should get 7" << std::endl << D[0] << std::endl;
    if(D[0] != 7)
    {
        return 1;
    }

    return 0;
}

int main()
{
    return check_dense_operator();
}
