#ifndef MATRIX_HEADER
#define MATRIX_HEADER

/** \class Matrix
  * 
  * \brief A class to construct an arbitrarily sized matrix or vector.
  */
template<typename Type, int Rows, int Cols> 
class Matrix {
    public:
    Matrix<Type, Rows, Cols>();
    void set(int row, int col, Type value);
    Type get(int row, int col);
    private:
    Type data[Rows * Cols];
}; // class Matrix

template<typename Type>
Matrix<Type, 2, 2> Identity2f();

// Understandable type aliases
typedef Matrix<float, 2, 2> Matrix2f;

inline Matrix<float, 2, 2> Identity2f()
{
    Matrix<float, 2, 2> m{};
    m.set(0, 0, 1.0);
    m.set(1, 1, 1.0);
    return m;
}

template <typename Type, int Rows, int Cols>
inline Matrix<Type, Rows, Cols>::Matrix()
{
  for (unsigned int row = 0; row < Rows; row++){
    for (unsigned int col = 0; col < Cols; col++){
      data[Cols * row + col] = 0;
    }
  }
}

template <typename Type, int Rows, int Cols>
inline void Matrix<Type, Rows, Cols>::set(int row, int col, Type value)
{
    data[Cols * row + col] = value;
}

template <typename Type, int Rows, int Cols>
inline Type Matrix<Type, Rows, Cols>::get(int row, int col)
{
    return data[Cols * row + col];
}

#endif
