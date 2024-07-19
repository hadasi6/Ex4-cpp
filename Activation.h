// Activation.h
#ifndef ACTIVATION_H
#define ACTIVATION_H

#include "Matrix.h"

// Insert Activation namespace here...

typedef Matrix (*ActivationFunction)(const Matrix&);

namespace activation {

// Typedef for activation function pointer
//    typedef Matrix (*ActivationFunction)(const Matrix&);

// ReLU activation function
    Matrix relu(const Matrix& m);

// Softmax activation function
    Matrix softmax(const Matrix& m);


} // namespace activation




#endif //ACTIVATION_H