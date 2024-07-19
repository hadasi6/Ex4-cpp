//
// Created by Owner on 18/07/2024.
//

#include "Dense.h"

Dense::Dense(const Matrix &weights, const Matrix &bias,
             ActivationFunction activation_func):
              _weights(weights),
              _bias(bias),
              _activation_func(activation_func)
{
  if (weights.get_rows() != bias.get_rows())
  {
    throw std::out_of_range("Matrix subscript out of bounds.");
  }
  if (bias.get_cols() != 1)
  {
    throw std::out_of_range("Matrix subscript out of bounds."); //todo-change
  }
  _weights = weights;
  _bias = bias;
  _activation_func = activation_func;
}

Matrix Dense::get_weights() const
{
  return _weights;
}

Matrix Dense::get_bias() const
{
  return _bias;
}

ActivationFunction Dense::get_activation() const
{
  return _activation_func;
}

Matrix Dense::operator()(const Matrix& input) const
{
  return _activation_func((_weights*input)+_bias);
}