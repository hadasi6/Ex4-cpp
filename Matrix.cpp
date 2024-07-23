#include <cmath>
#include <cstring>
#include "Matrix.h"
#include <algorithm>
#include <iostream>
#include <stdexcept>

#define DEFAULT_ROWS_SIZE 1
#define DEFAULT_COLS_SIZE 1
#define ONE_COL 1
#define DEFAULT_ELEMENT 0
#define LIMIT 0.1
#define OUT_OF_RANGE "Matrix dimensions must agree for addition."
#define DIMENSIONS_MUST_MATCH "Matrix dimensions must match for dot product."
#define CANNOT_FIND_ARGMAX "Cannot find argmax of an empty matrix."
#define SUBSCRIPT_OUT_OF_BOUNDS "Matrix subscript out of bounds."
#define INVALID_DATA_SIZE "Input stream doesn't have enough data to fill the"\
                            "matrix."
#define INVALID_MATRIX_DIMENSIONS "Matrix dimensions must be positive."
enum EnumBinaryReadResult
{
    BINARY_READ_SUCCESS = 0,
    BINARY_OPEN_FAILURE,
    BINARY_FILE_SIZE_FAILURE,
    BINARY_READ_FAILURE
};

Matrix::Matrix ()
    : Matrix (DEFAULT_ROWS_SIZE, DEFAULT_COLS_SIZE)
{}

Matrix::Matrix (int rows, int cols)
    : _rows (rows), _cols (cols), _data (new float[1])
{
  if (rows <= 0 || cols <= 0)
  {
    throw std::runtime_error (INVALID_MATRIX_DIMENSIONS);
  }
  delete[] _data;
  _data = new float[_rows * _cols];
  for (int i = 0; i < _rows * _cols; i++)
  {
    _data[i] = DEFAULT_ELEMENT;
  }
}

Matrix::Matrix (const Matrix &m)
{
  _rows = m._rows;
  _cols = m._cols;
  _data = new float[_rows * _cols];
  for (int i = 0; i < _rows * _cols; i++)
  {
    _data[i] = m._data[i];
  }
}

Matrix::~Matrix ()
{
  delete[] _data;
}

int Matrix::get_rows () const
{
  return _rows;
}

int Matrix::get_cols () const
{
  return _cols;
}


Matrix &Matrix::transpose ()
{
  // Allocate new memory for the transposed data
  auto *new_data = new float[_rows * _cols];
  // Transpose the data
  for (int i = 0; i < _rows; ++i)
  {
    for (int j = 0; j < _cols; ++j)
    {
      new_data[j * _rows + i] = _data[i * _cols + j];
    }
  }
  // Swap the data pointers
  delete[] _data;
  _data = new_data;
  // Swap the row and column counts
  std::swap (_rows, _cols);
  return *this;
}

Matrix &Matrix::vectorize ()
{
  _rows = _cols * _rows;
  _cols = ONE_COL;
  return *this;
}

void Matrix::plain_print () const
{
  for (int i = 0; i < _rows; i++)
  {
    for (int j = 0; j < _cols; j++)
    {
      std::cout << (*this) (i, j) << " ";
    }
    std::cout << std::endl;
  }
}

Matrix Matrix::dot (const Matrix &m) const
{
  if (_rows != m._rows || _cols != m._cols)
  {
    throw std::invalid_argument (DIMENSIONS_MUST_MATCH);
  }
  Matrix new_m (*this);
  for (int i = 0; i < _rows * _cols; i++)
  {
    new_m._data[i] *= m._data[i];
  }
  return new_m;
}

float Matrix::norm () const
{
  float elemnt_sum = 0.0;
  for (int i = 0; i < _rows * _cols; i++)
  {
    elemnt_sum += _data[i] * _data[i];
  }
  return std::sqrt (elemnt_sum);
}

void Matrix::swap_rows (int row1, int row2)
{
  for (int col = 0; col < _cols; ++col)
  {
    std::swap ((*this) (row1, col), (*this) (row2, col));
  }
}

void Matrix::divide_row (int row, float divisor)
{
  for (int col = 0; col < _cols; ++col)
  {
    (*this) (row, col) /= divisor;
  }
}

void Matrix::subtract_rows (int target_row, int source_row, float multiplier)
{
  for (int col = 0; col < _cols; ++col)
  {
    (*this) (target_row, col) -= multiplier * (*this) (source_row, col);
  }
}

Matrix Matrix::rref () const
{
  Matrix rref_m (*this);
  int lead = 0;
  for (int row = 0; row < _rows; ++row)
  {
    if (lead >= _cols)
    { return rref_m; }

    int i = row;
    while (rref_m (i, lead) == 0.0)
    {
      ++i;
      if (i == _rows)
      {
        i = row;
        ++lead;
        if (lead == _cols)
        { return rref_m; }
      }
    }

    rref_m.swap_rows (i, row);

    if (rref_m (row, lead) != 0.0)
    {
      rref_m.divide_row (row, rref_m (row, lead));
    }

    for (int index = 0; index < _rows; ++index)
    {
      if (index != row)
      {
        rref_m.subtract_rows (index, row, rref_m (index, lead));
      }
    }
    ++lead;
  }
  return rref_m;
}

int Matrix::argmax () const
{
  if (_rows <= 0 || _cols <= 0)
  {
    throw std::runtime_error (CANNOT_FIND_ARGMAX);
  }
  int max_index = 0;
  for (int i = 0; i < _rows * _cols; i++)
  {
    if (_data[i] > _data[max_index])
    {
      max_index = i;
    }
  }
  return max_index;
}

float Matrix::sum () const
{
  float total = 0.0;
  for (int i = 0; i < _rows * _cols; i++)
  {
    total += _data[i];
  }
  return total;
}

//operators:
Matrix &Matrix::operator+= (const Matrix &m)
{
  if (_rows != m._rows || _cols != m._cols)
  {
    throw std::invalid_argument (OUT_OF_RANGE);
  }
  for (int i = 0; i < _rows * _cols; i++)
  {
    _data[i] += m._data[i];
  }
  return *this;
}

Matrix Matrix::operator+ (const Matrix &m) const
{
  if (_rows != m._rows || _cols != m._cols)
  {
    throw std::invalid_argument (OUT_OF_RANGE);
  }
  Matrix new_m (*this);
  new_m += m;
  return new_m;
}

Matrix &Matrix::operator= (const Matrix &m)
{
  if (this == &m)
  {
    return *this;
  }
  delete[] _data;
  _rows = m._rows;
  _cols = m._cols;
  _data = new float[_rows * _cols];
  std::memcpy (_data, m._data, _rows * _cols * sizeof (float));
  return *this;
}

Matrix Matrix::operator* (const Matrix &m) const
{
  if (_cols != m._rows)
  {
    throw std::invalid_argument (OUT_OF_RANGE);
  }
  Matrix new_m (_rows, m._cols);
  for (int i = 0; i < new_m._rows; i++)
  {
    for (int j = 0; j < new_m._cols; j++)
    {
      for (int k = 0; k < _cols; k++)
      {
        new_m[i * new_m._cols + j] += (*this) (i, k) * m (k, j);
      }
    }
  }
  return new_m;
}

Matrix Matrix::operator* (float scalar) const
{
  Matrix new_m (*this);
  for (int i = 0; i < _rows * _cols; i++)
  {
    new_m._data[i] = _data[i] * scalar;
  }
  return new_m;
}

Matrix operator* (float scalar, const Matrix &m)
{
  return m * scalar;
}

float &Matrix::operator() (int row, int col)
{

  if (row < 0 || col < 0 || _rows < row || _cols < col)
  {
    throw std::out_of_range (SUBSCRIPT_OUT_OF_BOUNDS);
  }
  return _data[row * _cols + col];
}

float Matrix::operator() (int row, int col) const
{
  if (row >= _rows || col >= _cols)
  {
    throw std::out_of_range (SUBSCRIPT_OUT_OF_BOUNDS);
  }
  return _data[row * _cols + col];
}

float &Matrix::operator[] (int index)
{
  if (index < 0 || index > _rows * _cols)
  {
    throw std::out_of_range (SUBSCRIPT_OUT_OF_BOUNDS);
  }
  return _data[index];
}

float Matrix::operator[] (int index) const
{
  if (index < 0 || index > _rows * _cols)
  {
    throw std::out_of_range (SUBSCRIPT_OUT_OF_BOUNDS);
  }
  return _data[index];
}

std::ostream &operator<< (std::ostream &out, const Matrix &m)
{
  for (int i = 0; i < m._rows; ++i)
  {
    for (int j = 0; j < m._cols; ++j)
    {
      if (m (i, j) > LIMIT)
      { out << "**"; }
      else
      { out << " "; }
    }
    out << std::endl;
  }
  return out;
}

std::istream &operator>> (std::istream &in, Matrix &m)
{
  size_t array_size_bytes = m.get_rows () * m.get_cols () * sizeof (float);
  char *stream_in = new char[array_size_bytes];
  in.read (stream_in, static_cast<std::streamsize>(array_size_bytes));
  if (static_cast<size_t>(in.gcount ()) != array_size_bytes)
  {
    delete[] stream_in;
    throw std::runtime_error (INVALID_DATA_SIZE);
  }
  int stream_i = 0;
  for (int i = 0; i < m.get_rows (); i++)
  {
    for (int j = 0; j < m.get_cols (); j++)
    {
      float val;
      memcpy (&val, &stream_in[stream_i], sizeof (float));
      m (i, j) = val;
      stream_i += sizeof (float);
    }
  }
  delete[] stream_in; // clean buffer
  return in;
}