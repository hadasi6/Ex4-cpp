#include <cmath>
#include <cstring> //todo - for memcpy
#include "Matrix.h"
#include <algorithm>
#define DEFAULT_ROWS_SIZE 1
#define DEFAULT_COLS_SIZE 1
#define ONE_COL 1
#define DEFAULT_ELEMENT 0

Matrix::Matrix ()
: Matrix (DEFAULT_ROWS_SIZE, DEFAULT_COLS_SIZE)
{
//  _rows = DEFAULT_ROWS_SIZE;
//  _cols = DEFAULT_COLS_SIZE;
//  _data = new float[_rows * _cols]; //return Null_ptr if
  // allocation failed
//  for (int i = 0; i < _rows * _cols; i++)
//  {
//    _data[i] = DEFAULT_ELEMENT;
//  }
}


Matrix::Matrix (int rows, int cols)
: _rows(DEFAULT_ROWS_SIZE), _cols(DEFAULT_COLS_SIZE), _data(new float[_rows * _cols])
{
  if (rows <= 0 || cols <= 0)
  {
    std::cerr << "Invalid matrix dimensions" << std::endl; //todo
    throw std::runtime_error ("Matrix dimensions must be positive"); //todo
  }
//  _rows = rows;
//  _cols = cols;
//  _data = new float[_rows * _cols];
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
  Matrix temp_m(*this);
  for (int j=0; j < _cols; j++)
  {
    for (int i = 0; i < _rows; i++)
    {
      _data[j * _rows + i] = temp_m(i, j);
    }
  }
  int temp_rows = _rows;
  _rows = _cols;
  _cols = temp_rows;
  delete[] temp_m._data;
  return *this;
}


//Matrix &Matrix::transpose () //todo add &?
//{
//  float *new_data = new float[_rows * _cols];
//  for (int j=0; j < _cols; j++)
//  {
//    for (int i = 0; i < _rows; i++)
//    {
//      new_data[j * _rows + i] = (*this) (i, j);
//    }
//  }
//  int temp_rows = _rows;
//  _rows = _cols;
//  _cols = temp_rows;
//  delete[] _data;
//  _data = new_data;
//}

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
//  Matrix new_m(_rows, _cols);
  Matrix new_m(*this);
  for (int i = 0; i < _rows * _cols; i++)
  {
    new_m._data[i] *= m._data[i];
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


//void swap (float& a,float& b)
//{
//  float temp = a;
//  a=b;
//  b=temp;
//}

//helper
// פונקציה להחלפת שורות
void swapRows (Matrix& m, int row1, int row2)
{
  for (int col = 0; col < m.get_cols(); ++col)
  {
    float temp = m[row1*m.get_cols()+ col];
    m[row1* m.get_cols()+ col]= m(row2, col);
    m[row2*m.get_cols()+col] = temp;
//    swap(m(row1, col), m(row2, col)); //todo - changed into 3 lines ^
  }
}

//helper
// פונקציה לחילוק שורה במספר מסוים
void divideRow (Matrix& m, int row, float divisor)
{
  for (int col = 0; col < m.get_cols(); ++col)
  {
    //    m(row, col) = divisor;
    m[row*m.get_cols()+col] = m(row, col)/divisor; //todo -changed from^

  }
}

//helper
// פונקציה לחיסור שורות
void subtractRows (Matrix& m, int targetRow, int sourceRow, float multiplier)
{
  for (int col = 0; col < m.get_cols(); ++col)
  {
    m[targetRow*m.get_cols()+col] = m (targetRow, col)-m (sourceRow, col);
//    m (targetRow, col) -= multiplier * m (sourceRow, col); //todo - changed^
  }
}

// מימוש rref בעזרת פונקציות העזר
Matrix Matrix::rref () const
{
  Matrix rref_m (*this);     //todo -call copy constructor?
  int lead = 0;
  for (int row = 0; row < _rows; ++row)
  {
    if (lead >= _cols)
      return rref_m;

    int i = row;
    while (rref_m (i, lead) == 0)
    {
      ++i;
      if (i == _rows)
      {
        i = row;
        ++lead;
        if (lead == _cols)
          return rref_m;
      }
    }

    swapRows (rref_m, i, row);

    if (rref_m (row, lead) != 0)
    {
      divideRow (rref_m, row, rref_m (row, lead));
    }

    for (int index = 0; i < _rows; ++i)
    {
      if (index != row)
      {
        subtractRows (rref_m, index, row, rref_m (index, lead));
      }
    }
    ++lead;
  }
  return rref_m;
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
Matrix& Matrix::operator+= (const Matrix &m) //todo - validate cols==m_cols
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

Matrix Matrix::operator+(const Matrix &m) const
{
  if (_rows != m._rows || _cols != m._cols)
  {
    throw std::invalid_argument ("Matrix dimensions must agree for addition.");
  }
  Matrix new_m(*this);
  new_m += m;
  return new_m;
}

Matrix& Matrix::operator=(const Matrix &m)
{
  if (this == &m)
  {
    return *this;
  }
  delete[] _data;
  _rows = m._rows;
  _cols = m._cols;
  _data = new float[_rows*_cols];
  std::memcpy(_data, m._data, _rows * _cols * sizeof(float));
  return *this;
}

Matrix Matrix::operator*(const Matrix &m) const
{
  if (_cols != m._rows)
  {
    throw std::invalid_argument("Matrix dimensions must agree for multiplication.");
  }
  Matrix new_m(_rows, m._cols);
  for (int i = 0; i < _rows; ++i)
  {
    for (int j = 0; j < m._cols; ++j)
    {
      for (int k = 0; k < _cols; ++k)
      {
        new_m[i*_rows+j] += (*this)(i, k) * m(k, j);
//        new_m(i, j) += (*this)(i, k) * m(k, j); //todo -changed^
      }
    }
  }
  return new_m;
}

Matrix Matrix::operator*(float scalar) const
{
  Matrix new_m(*this);
  for (int i=0; i<_rows*_cols; i++)
  {
    new_m._data[i] = _data[i]*scalar; //todo
  }
  return new_m;
}


// Operator * (scalar) friend
Matrix operator*(float scalar, const Matrix &m)
{
  return m * scalar;
}

float Matrix::operator()(int row, int col)  //todo - i added const retur
{
  if (row<0 || col<0 ||  _rows <row || _cols<col) //todo - use get?
  {
    throw std::out_of_range("Matrix subscript out of bounds.");
  }
  return _data[row*_cols+ col];
}


float Matrix::operator()(int row, int col) const
{
  if (row >= _rows || col >= _cols)
  {
    throw std::out_of_range("Matrix subscript out of bounds.");
  }
  return _data[row * _cols + col];
}


float& Matrix::operator[](int index)
{
  if (index<0 || index> this->get_cols()* this->get_rows())
//  if (index<0 || index> _rows*_cols) //todo - validate
  {
    throw std::out_of_range("Matrix subscript out of bounds.");
  }
//  for (int i=0; i<index)
  return _data[index];
}

float Matrix::operator[](int index) const
{
  if (index<0 || index> _rows*_cols) //todo - validate
  {
    throw std::out_of_range("Matrix subscript out of bounds.");
  }
  return _data[index];
}

std::ostream& operator<<(std::ostream &out, const Matrix &m)
{
  for (int i = 0; i < m._rows; ++i)
  {
    for (int j = 0; j < m._cols; ++j)
    {
      if (m(i, j) > 0.1)
      {
        out << m(i, j) << "**";
      }
      else
      {
        out << m(i, j) << "  ";
      }
    }
    out << std::endl;
  }
  return out;
}


std::istream& operator>>(std::istream &in, Matrix &m)
{
  for (int i = 0; i < m._rows * m._cols; ++i) //todo - האם זו הכוונה?

  {
    if (!(in >> m._data[i]))
    {
      throw std::runtime_error("Error: Input stream does not have enough data to fill the matrix.");
    }
  }
  return in;
}
