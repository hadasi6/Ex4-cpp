#ifndef DENSE_H
#define DENSE_H

#include "Activation.h"

class Dense{
 private:
  Matrix _weights;
  Matrix _bias;
  ActivationFunction _activation_func;

 public:
  Dense(const Matrix& weights, const Matrix& bias,
        ActivationFunction activation_func);
  Matrix get_weights() const;
  Matrix get_bias() const;
  ActivationFunction get_activation() const;

  Matrix operator()(const Matrix& m) const;
};

#endif //DENSE_H