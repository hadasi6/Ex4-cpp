#include "Dense.h"
#include <iostream>

/**
 * Check if there isn't a default constructor for Dense.
 * call on const objects to make sure Dense getters are const functions
 * if this compiles and returns true we can pass
 * @return
 */
bool test_dense_constructor()
{
    std::cout << "testing if there isn't a default constructor for Dense" << std::endl;
    // there is no default constructor in Dense class.
    // this program is supposed to not compile (it's the normal case in TestNCompilation).
    Dense d = Dense();
    return true;
}

int main()
{
    test_dense_constructor();
}
