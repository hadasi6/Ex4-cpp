//
// Created by Owner on 18/07/2024.
//
#include "Matrix.h"
#include "Activation.h"
#include <cmath>

Matrix activation::relu (const Matrix &m)
{
  Matrix new_m(m.get_rows(), m.get_cols());
  for (int i=0; i<new_m.get_rows()*new_m.get_cols();i++)
  {
    if (m[i]>=0)
    {
      new_m[i]=m[i];
    }
    else
    {
      new_m[i]=0;
    }
  }
  return new_m;
}

Matrix activation::softmax(const Matrix &m)
{
  Matrix new_m(m);
  for (int i=0; i<(m.get_rows()*m.get_cols()); i++)
  {
    new_m[i]=std::exp(m[i]);
  }
  return (1/new_m.sum())*new_m;
}
