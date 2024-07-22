#include "MlpNetwork.h"
#define SHIFT 1

MlpNetwork::MlpNetwork (const Matrix *weights, const Matrix *biases)
{
  for (int i=0; i< MLP_SIZE; i++)
  {
    _weights[i]=weights[i];
    _biases[i]=biases[i];
  }
}

digit MlpNetwork::operator()(const Matrix& img) const
{
  Matrix output=img;
  for (int i=0; i<MLP_SIZE-SHIFT; i++)
  {
    output=Dense(_weights[i], _biases[i], activation::relu)(output);
  }
  output=Dense(_weights[MLP_SIZE-SHIFT], _biases[MLP_SIZE-SHIFT],
               activation::softmax)
      (output);
  unsigned int result = output.argmax();
  float prob = output[(int)result];
  return {result, prob};
}