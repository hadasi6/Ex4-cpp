#ifndef ACTIVATION_H
#define ACTIVATION_H

#include "Matrix.h"

// Typedef for activation function pointer
typedef Matrix (*ActivationFunction)(const Matrix&);

// namespace activation
namespace activation {

// ReLU activation function
    Matrix relu(const Matrix& m);

// Softmax activation function
    Matrix softmax(const Matrix& m);
}

#endif //ACTIVATION_H