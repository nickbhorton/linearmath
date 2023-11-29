#ifndef MATRIX_HEADER
#define MATRIX_HEADER

#include <iostream>
#include <tuple>

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
    Matrix<Type, Cols, Rows> transpose();

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
inline Matrix<Type, Rows, Cols>::Matrix() : RowColOrd{true}
{
    for (unsigned int i = 0; i < Rows * Cols; i++){
        data[i] = 0;
    }
}

template <typename Type, int Rows, int Cols>
inline Matrix<Type, Rows, Cols>::Matrix(bool RowColOrd) : RowColOrd{RowColOrd} {
    for (unsigned int i = 0; i < Rows * Cols; i++){
        data[i] = 0;
    }
}

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

template <typename Type, int Rows, int Cols>
Matrix<Type, Rows, Cols> operator*(const Type lhs, const Matrix<Type, Rows, Cols>& rhs) {
    Matrix<Type, Rows, Cols> result {};
    for (int i = 0; i < Rows; i++){
        for (int j = 0; j < Cols; j++){
            result.set(i, j, lhs * rhs.get(i, j));
        }
    }
    return result;
}

template <typename Type, int Rows, int Cols>
Matrix<Type, Rows, Cols> operator*(const Matrix<Type, Rows, Cols>& lhs, const Type rhs) {
    Matrix<Type, Rows, Cols> result {};
    for (int i = 0; i < Rows; i++){
        for (int j = 0; j < Cols; j++){
            result.set(i, j, lhs.get(i, j) * rhs);
        }
    }
    return result;
}


template <typename Type, int Rows, int Cols>
Matrix<Type, Rows, Cols> operator+(const Matrix<Type, Rows, Cols>& lhs, const Matrix<Type, Rows, Cols>& rhs) {
    Matrix<Type, Rows, Cols> result {};
    for (int i = 0; i < Rows; i++){
        for (int j = 0; j < Cols; j++){
            result.set(i, j, lhs.get(i, j) + rhs.get(i, j));
        }
    }
    return result;
}

template <typename Type, int Rows, int Cols>
Matrix<Type, Rows, Cols> operator-(const Matrix<Type, Rows, Cols>& lhs, const Matrix<Type, Rows, Cols>& rhs) {
    Matrix<Type, Rows, Cols> result {};
    for (int i = 0; i < Rows; i++){
        for (int j = 0; j < Cols; j++){
            result.set(i, j, lhs.get(i, j) - rhs.get(i, j));
        }
    }
    return result;
}

template <typename Type, int Rows, int Cols>
std::ostream& operator<<(std::ostream& os, const Matrix<Type, Rows, Cols>& m){
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++){
            os << m.get(i, j) << " ";
        }
        if (i != Rows - 1){
            os << "\n";
        }
    }
    return os;
}

template <typename Type, int Rows, int Cols>
inline Matrix<Type, Cols, Rows> Matrix<Type, Rows, Cols>::transpose()
{
    Matrix<Type, Cols, Rows> result{};
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++){
            result.set(j, i, get(i, j));
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

// Useful functionality

namespace mat{
    template <typename Type>
    inline Matrix<Type, 2, 2> create(const Matrix<Type, 2, 1>& v1, const Matrix<Type, 2, 1>& v2) {
        Matrix<Type, 2, 2> m {};
        m.set(0, 0, v1.get(0, 0));
        m.set(1, 0, v1.get(1, 0));
        m.set(0, 1, v2.get(0, 0));
        m.set(1, 1, v2.get(1, 0));
        return m;
    }

    template <typename Type>
    inline Matrix<Type, 2, 2> create(const Matrix<Type, 1, 2>& v1, const Matrix<Type, 1, 2>& v2) {
        Matrix<Type, 2, 2> m {};
        m.set(0, 0, v1.get(0, 0));
        m.set(0, 1, v1.get(0, 1));
        m.set(1, 0, v2.get(0, 0));
        m.set(1, 1, v2.get(0, 1));
        return m;
    }

    template <typename Type>
    inline Matrix<Type, 3, 3> create(const Matrix<Type, 3, 1>& v1, const Matrix<Type, 3, 1>& v2, const Matrix<Type, 3, 1>& v3) {
        Matrix<Type, 3, 3> m {};
        m.set(0, 0, v1.get(0, 0));
        m.set(1, 0, v1.get(1, 0));
        m.set(2, 0, v1.get(2, 0));
        m.set(0, 1, v2.get(0, 0));
        m.set(1, 1, v2.get(1, 0));
        m.set(2, 1, v2.get(2, 0));
        m.set(0, 2, v3.get(0, 0));
        m.set(1, 2, v3.get(1, 0));
        m.set(2, 2, v3.get(2, 0));
        return m;
    }

    template <typename Type>
    inline Matrix<Type, 3, 3> create(const Matrix<Type, 1, 3>& v1, const Matrix<Type, 1, 3>& v2, const Matrix<Type, 1, 3>& v3) {
        Matrix<Type, 3, 3> m {};
        m.set(0, 0, v1.get(0, 0));
        m.set(0, 1, v1.get(0, 1));
        m.set(0, 2, v1.get(0, 2));
        m.set(1, 0, v2.get(0, 0));
        m.set(1, 1, v2.get(0, 1));
        m.set(1, 2, v2.get(0, 2));
        m.set(2, 0, v3.get(0, 0));
        m.set(2, 1, v3.get(0, 1));
        m.set(2, 2, v3.get(0, 2));
        return m;
    }

    template <typename Type>
    inline Matrix<Type, 4, 4> create(const Matrix<Type, 3, 1>& v1, const Matrix<Type, 3, 1>& v2, const Matrix<Type, 3, 1>& v3, const Type& w) {
        Matrix<Type, 4, 4> m {};
        m.set(0, 0, v1.get(0, 0));
        m.set(1, 0, v1.get(1, 0));
        m.set(2, 0, v1.get(2, 0));
        m.set(0, 1, v2.get(0, 0));
        m.set(1, 1, v2.get(1, 0));
        m.set(2, 1, v2.get(2, 0));
        m.set(0, 2, v3.get(0, 0));
        m.set(1, 2, v3.get(1, 0));
        m.set(2, 2, v3.get(2, 0));
        
        m.set(3, 3, w);
        return m;
    }

    template <typename Type>
    inline Matrix<Type, 4, 4> create(const Matrix<Type, 1, 3>& v1, const Matrix<Type, 1, 3>& v2, const Matrix<Type, 1, 3>& v3, const Type& w) {
        Matrix<Type, 4, 4> m {};
        m.set(0, 0, v1.get(0, 0));
        m.set(0, 1, v1.get(0, 1));
        m.set(0, 2, v1.get(0, 2));
        m.set(1, 0, v2.get(0, 0));
        m.set(1, 1, v2.get(0, 1));
        m.set(1, 2, v2.get(0, 2));
        m.set(2, 0, v3.get(0, 0));
        m.set(2, 1, v3.get(0, 1));
        m.set(2, 2, v3.get(0, 2));

        m.set(3, 3, w);
        return m;
    }
}

namespace vec{
    /** \brief by default creates a column vector. Transpose if a row vector is wanted
      * 
      */
    template <typename Type>
    inline Matrix<Type, 2, 1> create(const Type &t1, const Type &t2)
    {
        Matrix<Type, 2, 1> v {};
        v.set(0, 0, t1);
        v.set(1, 0, t2);
        return v;
    }

    template <typename Type>
    inline Matrix<Type, 3, 1> create(const Type &t1, const Type &t2, const Type &t3)
    {
        Matrix<Type, 3, 1> v {};
        v.set(0, 0, t1);
        v.set(1, 0, t2);
        v.set(2, 0, t3);
        return v;
    }

    template <typename Type>
    inline Matrix<Type, 3, 1> create(const Type &t1, const Type &t2, const Type &t3, const Type &t4)
    {
        Matrix<Type, 3, 1> v {};
        v.set(0, 0, t1);
        v.set(1, 0, t2);
        v.set(2, 0, t3);
        v.set(3, 0, t4);
        return v;
    }
}

// Understandable type aliases
template<typename Type, int Size>
using RowVector = Matrix<Type, 1, Size>; 

template<typename Type, int Size>
using ColVector = Matrix<Type, Size, 1>; 

typedef Matrix<float, 2, 2> mat2f;
typedef Matrix<float, 3, 3> mat3f;
typedef Matrix<float, 4, 4> mat4f;

typedef Matrix<int, 2, 2> mat2i;
typedef Matrix<int, 3, 3> mat3i;
typedef Matrix<int, 4, 4> mat4i;

typedef ColVector<float, 2> vec2f;
typedef ColVector<float, 3> vec3f;
typedef ColVector<float, 4> vec4f;

typedef ColVector<int, 2> vec2i;
typedef ColVector<int, 3> vec3i;
typedef ColVector<int, 4> vec4i;

typedef RowVector<float, 2> rvec2f;
typedef RowVector<float, 3> rvec3f;
typedef RowVector<float, 4> rvec4f;

typedef RowVector<int, 2> rvec2i;
typedef RowVector<int, 3> rvec3i;
typedef RowVector<int, 4> rvec4i;


#endif
