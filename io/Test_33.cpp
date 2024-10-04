#include "autotest_utils.h"

/**
 * RREF Test 3.
 * Tests single row and single column matrices, essentially vectors
 */
int main(){
    std::cout << "checking RREF test 3" << std::endl;
    int rows, cols;
    int test_1_pass,test_2_pass,test_3_pass,test_4_pass,test_5_pass, test_6_pass;

    // Single row ordered ascending
    float arr2[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    float sol2[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    rows = 1; cols = 10;
    test_1_pass = test_reduced_matrix(arr2, sol2, rows, cols);



    // Single row ordered descending
    float arr3[10] = {9,8,7,6,5,4,3,2,1,0};
    float sol3[10] = {1,0.8888888,
                      0.7777777,
                      0.6666666,
                      0.5555555,
                      0.4444444,
                      0.3333333,
                      0.2222222,
                      0.1111111,
                      0};
    rows = 1; cols = 10;
    test_2_pass = test_reduced_matrix(arr3, sol3, rows, cols);



    // Single row zeroes
    float arr4[10] = {0};
    float sol4[10] = {0};
    rows = 1; cols = 10;
    test_3_pass = test_reduced_matrix(arr4, sol4, rows, cols);



    // Single col ordered ascending
    float arr5[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    float sol5[10] = {1,0,0,0,0,0,0,0,0,0};
    rows = 10; cols = 1;
    test_4_pass = test_reduced_matrix(arr5, sol5, rows, cols);



    // Single col ordered descending
    float arr6[10] = {9,8,7,6,5,4,3,2,1,0};
    float sol6[10] = {1,0,0,0,0,0,0,0,0,0};
    rows = 10; cols = 1;
    test_5_pass = test_reduced_matrix(arr6, sol6, rows, cols);



    // Single col zeroes
    float arr7[10] = {0};
    float sol7[10] = {0};
    rows = 10; cols = 1;
    test_6_pass  = test_reduced_matrix(arr7, sol7, rows, cols);


    // If all are zero then passed the test
    return test_1_pass || test_2_pass || test_3_pass || test_4_pass || test_5_pass || test_6_pass;

}