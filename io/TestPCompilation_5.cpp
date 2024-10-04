#include "MlpNetwork.h"
#include <iostream>
#include "autotest_utils.h"

/**
 * Check if there is a const version for MlpNetwork::operator()
 * call on const objects to make sure Dense getters are const functions
 * if this compiles and returns true we can pass
 * @return
 */
void check_const_mlp()
{
    std::cout << "testing if there is a const version for MlpNetwork::operator()" << std::endl;
    Matrix t = 0.01 * get_ordered_matrix(5, 5);
    Matrix t2 = 0.5 * get_ordered_matrix(5, 1);
    Matrix w[MLP_SIZE] = {Matrix(t), Matrix(t), Matrix(t), Matrix(t)};

    Matrix b[MLP_SIZE] = {Matrix(t2), Matrix(t2), Matrix(t2), Matrix(t2)};

    const MlpNetwork n(w, b);
    Matrix x = get_ordered_matrix(5, 1);
    digit res = n(x);
    std::cout << "got " << res.value << " @ " << res.probability * 100 << "%" << std::endl;
}

int main()
{
    check_const_mlp();
}
