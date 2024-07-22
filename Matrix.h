// Matrix.h
#ifndef MATRIX_H
#define MATRIX_H

//
#include <iostream>
//

// You don't have to use the struct. Can help you with MlpNetwork.h
struct matrix_dims
{
    int rows, cols;
};

class Matrix
{
 private:
  int _rows, _cols;
  float* _data;
  void swap_rows(int row1, int row2);
  void divide_row (int row, float divisor);
  void subtract_rows(int targetRow, int sourceRow, float multiplier);

 public:
  //methods & functions:
  Matrix();
  Matrix (int rows, int cols);
  Matrix (const Matrix &m);
  ~Matrix ();

  //getter:
  int get_rows() const;
  int get_cols() const;

  Matrix& transpose();
  Matrix& vectorize();
  void plain_print() const;
  Matrix dot(const Matrix& m) const;
  float norm() const;
  Matrix rref() const;
  int argmax() const;
  float sum() const;

  //operators:
  Matrix& operator+=(const Matrix &m);
  Matrix operator+(const Matrix &m) const;
  Matrix& operator=(const Matrix &m);
  Matrix operator*(const Matrix &m) const;
  Matrix operator*(float scalar) const;
  friend Matrix operator*(float scalar, const Matrix &m);
  float& operator()(int row, int col);
  float operator()(int row, int col) const;
  float& operator[](int index);
  float operator[](int index) const;
  //
  friend std::ostream& operator<<(std::ostream &out, const Matrix &m);
  friend std::istream& operator>>(std::istream &in, Matrix &m);
};

#endif //MATRIX_H