#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>

// You don't have to use the struct. Can help you with MlpNetwork.h
struct matrix_dims
{
    int rows, cols;
};

// Class representing a Matrix with various operations
class Matrix
{
 private:
  int _rows, _cols; // Number of rows and columns in the matrix
  float *_data;     // Pointer to the matrix data stored in a linear array

  // Helper function to swap two rows in the matrix
  void swap_rows (int row1, int row2);

  // Helper function to divide a row by a given divisor
  void divide_row (int row, float divisor);

  // Helper function to subtract a multiple of one row from another
  void subtract_rows (int targetRow, int sourceRow, float multiplier);

 public:
  // Default constructor: initializes a 1x1 matrix with a default value
  Matrix ();

  // Parameterized constructor: initializes a matrix with given dimensions
  Matrix (int rows, int cols);

  // Copy constructor: creates a new matrix as a copy of an existing matrix
  Matrix (const Matrix &m);

  // Destructor: deallocates the memory used by the matrix
  ~Matrix ();

  // Getter for the number of rows in the matrix
  int get_rows () const;

  // Getter for the number of columns in the matrix
  int get_cols () const;

  // Transposes the matrix (swaps rows and columns) and returns a reference
  // to the transposed matrix
  Matrix &transpose ();

  // Vectorizes the matrix (converts it to a single column vector) and
  // returns a reference to the vectorized matrix
  Matrix &vectorize ();

  // Prints the matrix to the standard output
  void plain_print () const;

  // Computes the dot product of this matrix with another matrix
  Matrix dot (const Matrix &m) const;

  // Computes the Frobenius norm of the matrix
  float norm () const;

  // Reduces the matrix to its row echelon form
  Matrix rref () const;

  // Returns the index of the maximum element in the matrix
  int argmax () const;

  // Computes the sum of all elements in the matrix
  float sum () const;

  // Operator overloading:
  // Adds another matrix to this matrix
  Matrix &operator+= (const Matrix &m);
  // Returns the sum of this matrix and another matrix
  Matrix operator+ (const Matrix &m) const;
  // Assigns another matrix to this matrix
  Matrix &operator= (const Matrix &m);
  // Multiplies this matrix by another matrix
  Matrix operator* (const Matrix &m) const;
  // Multiplies this matrix by a scalar
  Matrix operator* (float scalar) const;
  // Multiplies a scalar by a matrix (friend function)
  friend Matrix operator* (float scalar, const Matrix &m);
  // Accesses an element in the matrix by row and column
  float &operator() (int row, int col);
  // Accesses an element in the matrix by row and column (const version)
  float operator() (int row, int col) const;
  // Accesses an element in the matrix by linear index
  float &operator[] (int index);
  // Accesses an element in the matrix by linear index (const version)
  float operator[] (int index) const;
  // Outputs the matrix to a stream
  friend std::ostream &operator<< (std::ostream &out, const Matrix &m);
  // Inputs the matrix from a stream
  friend std::istream &operator>> (std::istream &in, Matrix &m);
};

#endif //MATRIX_H