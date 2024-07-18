//
// Created by Owner on 18/07/2024.
//
#include "MlpNetwork.h"

MlpNetwork::MlpNetwork (const Matrix *weights, const Matrix *biases)
{
  for (int i=0; i< MLP_SIZE; i++)
  {
    _weights[i]=weights[i];
    _biases[i]=biases[i];
  }
}

digit MlpNetwork::operator()(const Matrix& img)
{
  Matrix output=img;
  for (int i=0; i<MLP_SIZE-1; i++)
  {
    output=Dense(_weights[i], _biases[i], activation::relu)(output);
  }
  output=Dense(_weights[MLP_SIZE-1], _biases[MLP_SIZE-1], activation::softmax)
      (output);
  unsigned int result = output.argmax();
  float prob = output[(int)result];
  return {result, prob};
}

