#include "autotest_utils.h"

/**
 * RREF Test 5.
 * Tests matrices with one or two columns of zeroes, and one or two rows of zeroes
 */
int main(){
    std::cout << "checking RREF test 5" << std::endl;
    int rows, cols;
    int test_1_pass,test_2_pass,test_3_pass,test_4_pass,test_5_pass,test_6_pass;

    // One empty column, rows<cols
    float arr_17[12] = {2,0,2,6,1,0,1,7,3,0,2,4};
    float sol_17[12] = {1,0,0,0,0,0,1,0,0,0,0,1};
    rows = 3; cols = 4;
    test_1_pass = test_reduced_matrix(arr_17, sol_17, rows, cols);


    // One empty column, rows>cols
    float arr_18[12] = {2,0,2,1,0,1,3,0,2,1,0,3};
    float sol_18[12] = {1,0,0,0,0,1,0,0,0,0,0,0};
    rows = 4; cols = 3;
    test_2_pass = test_reduced_matrix(arr_18, sol_18, rows, cols);


    // Two empty columns, rows<cols
    float arr_19[18] = {2,0,2,4,0,4,0,0,1,3,0,5,3,0,2,4,0,5};
    float sol_19[18] = {1,0,0,0,0,1,0,0,1,0,0,-7,0,0,0,1,0,4};
    rows = 3; cols = 6;
    test_3_pass = test_reduced_matrix(arr_19, sol_19, rows, cols);


    // Two empty columns, rows>cols
    float arr_20[35] = {0,0,2,4,0,0,0,1,3,0,0,0,7,5,0,0,5,0,0,0,0,6,0,7,0,0,4,0,8,0,0,2,0,9,0};
    float sol_20[35] = {0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    rows = 7; cols = 5;
    test_4_pass = test_reduced_matrix(arr_20, sol_20, rows, cols);




    //1 Row of Zeroes
    float arr21[16] = {0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0};
    float sol21[16] = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0};
    rows = 4; cols = 4;
    test_5_pass = test_reduced_matrix(arr21, sol21, rows, cols);

    //2 Row of Zeroes
    float arr22[20] = {0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0};
    float sol22[20] = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0};
    rows = 5; cols = 4;
    test_6_pass = test_reduced_matrix(arr22, sol22, rows, cols);

    // If all are zero then passed the test
    return test_1_pass || test_2_pass || test_3_pass || test_4_pass || test_5_pass || test_6_pass;


}