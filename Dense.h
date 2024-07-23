#ifndef DENSE_H
#define DENSE_H

#include "Activation.h"

class Dense{
 private:
  Matrix _weights;  // Weights matrix
  Matrix _bias;     // Bias vector
  ActivationFunction _activation_func;  // Activation function

 public:
  //Constructs a Dense layer with given weights, bias, and activation function.
  Dense(const Matrix& weights, const Matrix& bias,
        ActivationFunction activation_func);
  //Gets the weights matrix.
  Matrix get_weights() const;
  //Gets the bias vector.
  Matrix get_bias() const;
  //Gets the activation function.
  ActivationFunction get_activation() const;
  //Applies the Dense layer to an input matrix.
  Matrix operator()(const Matrix& m) const;
};

#endif //DENSE_H