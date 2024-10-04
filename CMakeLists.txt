cmake_minimum_required(VERSION 3.28)
project(ex4_hadas6)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ex4_hadas6
        Activation.h
        Dense.h
        main.cpp
        Matrix.h
        MlpNetwork.h
        Matrix.cpp
        Activation.h
        Activation.cpp
        Dense.h
        Dense.cpp
        MlpNetwork.cpp)
#
#add_executable(matrix_test
#        Matrix.cpp
#        Matrix.h
#        temp.cpp
#)

add_executable(test_31
        Activation.h
        Dense.h
        io/Test_31.cpp
        io/autotest_utils.h
        Matrix.h
        MlpNetwork.h
        Matrix.cpp
        Activation.h
        Activation.cpp
        Dense.h
        Dense.cpp
        MlpNetwork.cpp)

add_executable(test_5
        Activation.h
        Dense.h
        io/Test_5.cpp
        io/autotest_utils.h
        Matrix.h
        MlpNetwork.h
        Matrix.cpp
        Activation.h
        Activation.cpp
        Dense.h
        Dense.cpp
        MlpNetwork.cpp)

add_executable(test_12
        Activation.h
        Dense.h
        io/Test_12.cpp
        io/autotest_utils.h
        Matrix.h
        MlpNetwork.h
        Matrix.cpp
        Activation.h
        Activation.cpp
        Dense.h
        Dense.cpp
        MlpNetwork.cpp)