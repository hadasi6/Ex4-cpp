#ifndef ACTIVATION_H
#define ACTIVATION_H

#include "Matrix.h"

// Typedef for activation function pointer
typedef Matrix (*ActivationFunction)(const Matrix&);

// namespace activation
namespace activation {

// ReLU activation function
/**
     * Applies the ReLU activation function to a matrix.
     * ReLU (Rectified Linear Unit) sets all negative values to zero.
     * @param m Input matrix
     * @return Matrix with ReLU applied
     */
    Matrix relu(const Matrix& m);

    /**
     * Applies the Softmax activation function to a matrix.
     * Softmax normalizes the matrix values to be probabilities that sum up
     * to 1.
     * @param m Input matrix
     * @return Matrix with Softmax applied
     */
    Matrix softmax(const Matrix& m);
}

#endif //ACTIVATION_H