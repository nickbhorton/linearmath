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
    Type get(int row, int col) const;
    int rows() const;
    int cols() const;

    private:
    Type data[Rows * Cols];

    // Matrices are stored as arrays. The rows are contigious in memory
    // if ROWCOLORDER is true. Otherwise the columns are contigious
    bool RowColOrd;
}; // class Matrix

// Constructors

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

// Operators

template <typename Type, int RowsLHS, int RowsRHSColsLHS, int ColsRHS>
Matrix<Type, RowsLHS, ColsRHS> operator*(const Matrix<Type, RowsLHS, RowsRHSColsLHS>& lhs, const Matrix<Type, RowsRHSColsLHS, ColsRHS>& rhs) {
    Matrix<Type, RowsLHS, ColsRHS> result {};
    for (int i = 0; i < RowsLHS; i++){
        for (int j = 0; j < ColsRHS; j++){
            Type sum = 0;
            for (int k = 0; k < RowsRHSColsLHS; k++) {
                sum += lhs.get(i, k) * rhs.get(k, j);
            }
            result.set(i, j, sum);
        }
    }
    return result;
}

// Getters and Setters

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
inline Type Matrix<Type, Rows, Cols>::get(int row, int col) const
{

    if (RowColOrd){
        return data[Cols * row + col];
    }
    else {
        return data[Rows * col + row];
    }
}

template <typename Type, int Rows, int Cols>
inline int Matrix<Type, Rows, Cols>::rows() const {
    return Rows;
}

template <typename Type, int Rows, int Cols>
inline int Matrix<Type, Rows, Cols>::cols() const {
    return Cols;
}

// Understandable type aliases
typedef Matrix<float, 2, 2> Matrix2f;
typedef Matrix<float, 3, 3> Matrix3f;
typedef Matrix<float, 4, 4> Matrix4f;

typedef Matrix<int, 2, 2> Matrix2i;
typedef Matrix<int, 3, 3> Matrix3i;
typedef Matrix<int, 4, 4> Matrix4i;

typedef Matrix<float, 2, 1> Vector2f;
typedef Matrix<float, 3, 1> Vector3f;
typedef Matrix<float, 4, 1> Vector4f;
typedef Matrix<float, 1, 2> RowVector2f;
typedef Matrix<float, 1, 3> RowVector3f;
typedef Matrix<float, 1, 4> RowVector4f;

typedef Matrix<int, 2, 1> Vector2i;
typedef Matrix<int, 3, 1> Vector3i;
typedef Matrix<int, 4, 1> Vector4i;
typedef Matrix<int, 1, 2> RowVector2i;
typedef Matrix<int, 1, 3> RowVector3i;
typedef Matrix<int, 1, 4> RowVector4i;

#endif
