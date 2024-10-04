#include "autotest_utils.h"

/**
 * RREF Test 4.
 * Tests square and rectangle matrices with linearly independent and dependent rows
 */
int main(){
    std::cout << "checking RREF test 4" << std::endl;
    int rows, cols;
    int test_1_pass,test_2_pass,test_3_pass,test_4_pass;

    //Square Matrix, linearly independent rows
    float arr8[4] = {4,1,2,4};
    float sol8[4] = {1,0,0,1};
    rows = 2; cols = 2;
    test_1_pass = test_reduced_matrix(arr8, sol8, rows, cols);



    //Square Matrix, linearly dependent rows
    float arr9[4] = {4,8,2,4};
    float sol9[4] = {1,2,0,0};
    rows = 2; cols = 2;
    test_2_pass = test_reduced_matrix(arr9, sol9, rows, cols);



    //Rectangle Matrix, linearly independent rows
    float arr15[6] = {4,1,2,4,7,11};
    float sol15[6] = {1,0,0.125,0,1,1.5};
    rows = 2; cols = 3;
    test_3_pass = test_reduced_matrix(arr15, sol15, rows, cols);



    //Rectangle Matrix, linearly dependent rows
    float arr16[6] = {4,2,8,4,16,8};
    float sol16[6] = {1,0.5,0,0,0,0};
    rows = 3; cols = 2;
    test_4_pass = test_reduced_matrix(arr16, sol16, rows, cols);


    // If all are zero then passed the test
    return test_1_pass || test_2_pass || test_3_pass || test_4_pass;

}