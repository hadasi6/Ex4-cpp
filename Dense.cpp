#include "Dense.h"
#define SUBSCRIPT_OUT_OF_BOUNDS "Matrix subscript out of bounds."
#define NUM_VEC_COLS 1

Dense::Dense(const Matrix &weights, const Matrix &bias,
             ActivationFunction activation_func):
              _weights(weights),
              _bias(bias),
              _activation_func(activation_func)
{
  if (weights.get_rows() != bias.get_rows())
  {
    throw std::out_of_range(SUBSCRIPT_OUT_OF_BOUNDS);
  }
  if (bias.get_cols() != NUM_VEC_COLS)
  {
    throw std::out_of_range(SUBSCRIPT_OUT_OF_BOUNDS);
  }
//  _weights = weights; //todo
//  _bias = bias;
//  _activation_func = activation_func;
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