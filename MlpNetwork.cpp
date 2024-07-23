#include "MlpNetwork.h"
#define SHIFT 1
#define SUBSCRIPT_OUT_OF_BOUNDS "Matrix subscript out of bounds."

MlpNetwork::MlpNetwork (const Matrix *weights, const Matrix *biases)
{
  for (int i=0; i< MLP_SIZE; i++)
  {
    if (weights[i].get_rows() != weights_dims[i].rows || weights[i]
    .get_cols() != weights_dims[i].cols)
    {
      throw std::out_of_range(SUBSCRIPT_OUT_OF_BOUNDS);
    }
    if (biases[i].get_rows() != bias_dims[i].rows || biases[i].get_cols()
          !=bias_dims[i].cols)
    {
      throw std::out_of_range(SUBSCRIPT_OUT_OF_BOUNDS);
    }
    _weights[i]=weights[i];
    _biases[i]=biases[i];
  }
}

digit MlpNetwork::operator()(const Matrix& img) const
{
  Matrix output=img;
  //Forward pass through the network layers with ReLU activation for
  // hidden layers
  for (int i=0; i<MLP_SIZE-SHIFT; i++)
  {
    output=Dense(_weights[i], _biases[i], activation::relu)(output);
  }
  // Last layer with Softmax activation
  output=Dense(_weights[MLP_SIZE-SHIFT], _biases[MLP_SIZE-SHIFT],
               activation::softmax)
      (output);
  unsigned int result = output.argmax();
  float prob = output[(int)result];
  return {result, prob};
}