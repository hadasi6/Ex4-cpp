// Dense.h
#ifndef DENSE_H
#define DENSE_H

#include "Activation.h"

// Insert Dense class here...

class Dense{
 private:
  Matrix _weights;
  Matrix _bias;
  ActivationFunction _activation_func;
//  activation::ActivationFunction _activation_func;

//  Matrix (*activation)(const Matrix &);
 public:
  Dense(const Matrix& weights, const Matrix& bias,
        ActivationFunction activation_func);
  Matrix get_weights() const;
  Matrix get_bias() const;
  ActivationFunction get_activation() const; //todo - changed

//  Matrix operator()(const Matrix w, const Matrix b, Matrix activation);
  Matrix operator()(const Matrix& m) const;
};



#endif //DENSE_H