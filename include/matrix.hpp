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
    Matrix<Type, Rows, Cols>(bool RowColOrd);

    Matrix<Type, Rows, Cols> Identity();


    void set(int row, int col, Type value);
    Type get(int row, int col);
    int rows();
    int cols();

    private:
    Type data[Rows * Cols];

    // Matrices are stored as arrays. The rows are contigious in memory
    // if ROWCOLORDER is true. Otherwise the columns are contigious
    bool RowColOrd;
}; // class Matrix

template <typename Type, int Rows, int Cols>
inline Matrix<Type, Rows, Cols>::Matrix()
{
    RowColOrd = true;
    for (unsigned int i = 0; i < Rows * Cols; i++){
        data[i] = 0;
    }
}

template <typename Type, int Rows, int Cols>
inline Matrix<Type, Rows, Cols>::Matrix(bool RowColOrd) : RowColOrd{RowColOrd} {}

template <typename Type, int Rows, int Cols>
inline Matrix<Type, Rows, Cols> Matrix<Type, Rows, Cols>::Identity()
{
    Matrix<Type, Rows, Cols> m {};
    for (unsigned int row = 0; row < Rows; row++){
        for (unsigned int col = 0; col < Cols; col++){
            if (row == col)
            {
                m.set(row, col, 1);
            }
        }
    }
    return m;
}

template <typename Type, int Rows, int Cols>
inline void Matrix<Type, Rows, Cols>::set(int row, int col, Type value)
{
    if (RowColOrd){
        data[Cols * row + col] = value;
    }
    else {
        data[Rows * col + row] = value;
    }
}

template <typename Type, int Rows, int Cols>
inline Type Matrix<Type, Rows, Cols>::get(int row, int col)
{

    if (RowColOrd){
        return data[Cols * row + col];
    }
    else {
        return data[Rows * col + row];
    }
}

template <typename Type, int Rows, int Cols>
inline int Matrix<Type, Rows, Cols>::rows() {
    return Rows;
}

template <typename Type, int Rows, int Cols>
inline int Matrix<Type, Rows, Cols>::cols() {
    return Cols;
}

// Understandable type aliases
typedef Matrix<float, 2, 2> Matrix2f;

#endif
