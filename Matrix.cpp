#include <cmath>
#include "Matrix.h"
#define DEFAULT_ROWS_SIZE 1
#define DEFAULT_COLS_SIZE 1
#define ONE_COL 1
#define DEFAULT_ELEMENT 0

Matrix::Matrix ()
{
  _rows = DEFAULT_ROWS_SIZE;
  _cols = DEFAULT_COLS_SIZE;
  _data = new float[_rows * _cols]; //return Null_ptr if
  // allocation failed
  for (int i = 0; i < _rows * _cols; i++)
  {
    _data[i] = DEFAULT_ELEMENT;
  }
}

Matrix::Matrix (int rows, int cols)
{
  if (rows <= 0 || cols <= 0)
  {
    std::cerr << "Invalid matrix dimensions" << std::endl; //todo
    throw std::runtime_error ("Matrix dimensions must be positive"); //todo
  }
  _rows = rows;
  _cols = cols;
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

Matrix &Matrix::transpose () //todo add &?
{
  float *new_data = new float[_rows * _cols];
  for (int j=0; j < _cols; j++)
  {
    for (int i = 0; i < _rows; i++)
    {
      new_data[j * _rows + i] = (*this) (i, j);
    }
  }
  int temp_rows = _rows;
  _rows = _cols;
  _cols = temp_rows;
  delete[] _data;
  _data = new_data;
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
    throw std::invalid_argument ("Matrix dimensions must match for dot product.");
  }
  Matrix new_m(_rows, _cols);
  for (int i = 0; i < _rows * _cols; i++)
  {
    new_m._data[i] = _data[i] * m._data[i];
  }
  return new_m;
}

float Matrix::norm () const
{
  float elemnt_sum = 0.0f;  //todo -0 ?
  for (int i = 0; i < _rows * _cols; i++)
  {
    elemnt_sum += _data[i] * _data[i];
  }
  return std::sqrt (elemnt_sum);
}

//helper
// פונקציה להחלפת שורות
void swapRows (int row1, int row2)
{
  for (int col = 0; col < _cols; ++col)
  {
    std::swap ((*this) (row1, col), (*this) (row2, col));
  }
}

//helper
// פונקציה לחילוק שורה במספר מסוים
void Matrix::divideRow (int row, float divisor)
{
  for (int col = 0; col < _cols; ++col)
  {
    (*this) (row, col) /= divisor;
  }
}

//helper
// פונקציה לחיסור שורות
void Matrix::subtractRows (int targetRow, int sourceRow, float multiplier)
{
  for (int col = 0; col < _cols; ++col)
  {
    (*this) (targetRow, col) -= multiplier * (*this) (sourceRow, col);
  }
}

// מימוש rref בעזרת פונקציות העזר
Matrix Matrix::rref () const
{
  Matrix rref (*this);
  int lead = 0;
  for (int row = 0; row < _rows; ++row)
  {
    if (lead >= _cols)
      return rref;

    int i = row;
    while (rref (i, lead) == 0)
    {
      ++i;
      if (i == _rows)
      {
        i = row;
        ++lead;
        if (lead == _cols)
          return rref;
      }
    }

    rref.swapRows (i, row);

    if (rref (row, lead) != 0)
    {
      rref.divideRow (row, rref (row, lead));
    }

    for (int i = 0; i < _rows; ++i)
    {
      if (i != row)
      {
        rref.subtractRows (i, row, rref (i, lead));
      }
    }
    ++lead;
  }
  return rref;
}

int Matrix::argmax () const
{
  if (_rows <= 0 || _cols <= 0) // todo - del?
  {
    throw std::runtime_error ("Cannot find argmax of an empty matrix.");
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
  float total = 0; //todo -0.0f?
  for (int i = 0; i < _rows * _cols; ++i)  //todo -i++?
  {
    total += _data[i];
  }
  return total;
}

//operators:
Matrix::Matrix& operator+= (const Matrix &m) //todo - validate cols==m_cols
{
  if (_rows != m._rows || _cols != m._cols)
  {
    throw std::invalid_argument ("Matrix dimensions must agree for addition.");
  }
  for (int i=0; i < _rows*_cols; i++)
  {
    _data[i]+=m._data[i];
  }
  return *this;
}

Matrix::Matrix operator+(const Matrix &m) const
{
  if (_rows != m._rows || _cols != m._cols)
  {
    throw std::invalid_argument ("Matrix dimensions must agree for addition.");
  }
  Matrix new_m(*this);
  new_m += m;
  return new_m;
}

Matrix::Matrix& operator=(const Matrix &m)
{
  if (this == &m)
  {
    return *this;
  }
  delete[] _data;
  _rows = m.rows;
  _cols = m._cols;
  _data = new float[_rows*_cols];
  std::memcpy(_data, m._data, _rows * _cols * sizeof(float));
  return *this;
}

Matrix::Matrix operator*(const Matrix &m) const
{
  if (_cols != m._rows)
  {
    throw std::invalid_argument("Matrix dimensions must agree for multiplication.");
  }
  Matrix new_m(_rows, m._cols);
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < m.cols; ++j)
    {
      for (int k = 0; k < cols; ++k)
      {
        new_m(i, j) += (*this)(i, k) * m(k, j);
      }
    }
  }
  return new_m;
}

Matrix::Matrix operator*(float scalar) const
{
  const Matrix new_m(_rows, _cols);
  for (int i=0; i<_rows*_cols; i++)
  {
    new_m._data[i] = _data[i]*scalar;
  }
  return const new_m;
}