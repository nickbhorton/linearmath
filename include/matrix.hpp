#ifndef MATRIX_HEADER
#define MATRIX_HEADER

#include <iostream>
#include <tuple>
#include <cmath>

// For IDEs to be able to see header
#define PROCESSED

/** \class Matrix
  * 
  * \brief A class to construct an arbitrarily sized matrix or vector.
  */
template<typename Type, int Rows, int Cols> 
class Matrix {
    public:
    Matrix<Type, Rows, Cols>();
    Matrix<Type, Rows, Cols>(bool RowColOrd);

    Matrix<Type, Rows, Cols> identity() const;
    Matrix<Type, Cols, Rows> transpose() const;
    Matrix<Type, Rows - 1, Cols - 1> minor(int i, int j) const;
    Type det() const;

    Matrix<Type, Rows, Cols> operator+=(const Matrix<Type, Rows, Cols>& other);
    Matrix<Type, Rows, Cols> operator-=(const Matrix<Type, Rows, Cols>& other);
    Matrix<Type, Rows, Cols> operator*=(const Matrix<Type, Rows, Cols>& other);

    void set(int row, int col, Type value);
    Type get(int row, int col) const;
    int rows() const;
    int cols() const;
    bool is_square() const;

    private:
    Type data[Rows * Cols];

    // Matrices are stored as arrays. The rows are contigious in memory
    // if ROWCOLORDER is true. Otherwise the columns are contigious
    bool RowColOrd;
}; // class Matrix

#include "matrix_ops.hpp"
#include "matrix_functions.hpp"
#include "vector_functions.hpp"

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

// Member Functions

template <typename Type, int Rows, int Cols>
inline Matrix<Type, Rows, Cols> Matrix<Type, Rows, Cols>::identity() const
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
inline Matrix<Type, Cols, Rows> Matrix<Type, Rows, Cols>::transpose() const
{
    Matrix<Type, Cols, Rows> result{};
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++){
            result.set(j, i, get(i, j));
        }
    }
    return result;
}

template <typename Type, int Rows, int Cols>
Matrix<Type, Rows - 1, Cols - 1> Matrix<Type, Rows, Cols>::minor(int i, int j) const {
    Matrix<Type, Rows - 1, Cols - 1> result{};
    int major_i = 0;
    int major_j = 0;
    int minor_i = 0;
    int minor_j = 0;
    while (major_i < Rows){
        while (major_j < Cols){
            if (major_i != i && major_j != j){
                result.set(minor_i, minor_j, get(major_i, major_j));
                ++minor_j;
            }
            ++major_j;
        }
        if (major_i != i && major_j != j){
            ++minor_i;
        }
        ++major_i;
        major_j = 0;
        minor_j = 0;
    }

    return result;
}

template <typename Type, int Rows, int Cols>
Type Matrix<Type, Rows, Cols>::det() const {
    if constexpr(Rows == 2 && Cols == 2) {
        return get(0, 0) * get(1, 1) - get(0, 1) * get(1, 0);
    }
    else {
        Type sum = (Type) 0;
        for (int i = 0; i < Cols; i++){
            if (i % 2 == 0){
                sum += get(0, i) * minor(0, i).det();
            }
            else {
                sum -= get(0, i) * minor(0, i).det();
            }
        }
        return sum;
    }
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

template <typename Type, int Rows, int Cols>
inline bool Matrix<Type, Rows, Cols>::is_square() const {
    return Rows == Cols;
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
