//
// Created by Owner on 18/07/2024.
//

#include "Dense.h"

Dense::Dense(const Matrix &weights, const Matrix &bias,
             activation::ActivationFunction
              activation_func):
              _weights(weights),
              _bias(bias),
              _activation_func(activation_func)
{}

Matrix Dense::get_weights() const
{
  return _weights;
}

Matrix Dense::get_bias() const
{
  return _bias;
}

activation::ActivationFunction Dense::get_activation(const Matrix&) const
{
  return _activation_func;
}

Matrix Dense::operator()(const Matrix& input) const
{
  return _activation_func((_weights*input)+_bias);
}