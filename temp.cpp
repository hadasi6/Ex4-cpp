//
// Created by Owner on 17/07/2024.
//
#include "Matrix.h"

int main(int argc, char* argv[])
{
  Matrix m(4,3);
  Matrix s(3, 2);
  m.transpose();
  m[1] = 5;
  m[2] = 4;
  s[1] = 6;
  m(1,4) = 1;
  m.plain_print();
  m.vectorize();
  m.plain_print();
  s.plain_print();

}