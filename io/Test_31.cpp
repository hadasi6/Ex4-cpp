#include "autotest_utils.h"

/**
 *  RREF test 1.
 *  Tests identity matrix, zero matrix, jordan matrix, and single element zero and nonzero
 */
int main(){
    std::cout << "checking RREF test 1" << std::endl;
    int rows, cols;
    int test_1_pass,test_2_pass,test_3_pass,test_4_pass,test_5_pass;

    //Zero Matrix
    float arr1[20]={0};
    float sol1[20]={0};
    rows = 5; cols = 4;
    test_1_pass = test_reduced_matrix(arr1, sol1, rows, cols);


    //Identity Matrix
    float arr10[9] = {1,0,0,0,1,0,0,0,1};
    float sol10[9] = {1,0,0,0,1,0,0,0,1};
    rows = 3; cols = 3;
    test_2_pass = test_reduced_matrix(arr10, sol10, rows, cols);

    // Jordan Matrix for the hell of it
    float arr13[16] = {2,1,0,0,0,2,1,0,0,0,2,0,0,0,0,2};
    float sol13[16] = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};
    rows = 4; cols = 4;
    test_3_pass = test_reduced_matrix(arr13, sol13, rows, cols);

    //Single Element Non-zero
    float arr11[1] = {81};
    float sol11[1] = {1};
    rows = 1; cols = 1;
    test_4_pass = test_reduced_matrix(arr11, sol11, rows, cols);


    //Single Element Zero
    float arr12[1] = {0};
    float sol12[1] = {0};
    rows = 1; cols = 1;
    test_5_pass = test_reduced_matrix(arr12, sol12, rows, cols);


    return test_1_pass || test_2_pass || test_3_pass || test_4_pass || test_5_pass;  // If all are zero then passed the test
}