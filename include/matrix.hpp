#ifndef MATRIX_HEADER
#define MATRIX_HEADER

#include <iostream>
#include <cmath>
#include <array>
#include <initializer_list>


// For IDEs to be able to see header
#define PROCESSED

template<typename Type, int Size> class ColVector;
template<typename Type, int Size> class RowVector;

/** \class Matrix
  * 
  * \brief A class to construct an arbitrarily sized matrix or vector.
  * Always stored in column major order for multiplication optimizations
  */
template<typename Type, int Rows, int Cols> 
class Matrix {
    public:
    Matrix<Type, Rows, Cols>();
    Matrix<Type, Rows, Cols>(std::array<Type, Rows * Cols>  data);

    Matrix<Type, Rows, Cols> identity() const;
    Matrix<Type, Cols, Rows> transpose() const;
    Matrix<Type, Rows - 1, Cols - 1> minor(int i, int j) const;
    Type det() const;
    RowVector<Type, Cols> row (unsigned int i);
    ColVector<Type, Rows> col (unsigned int i);

    Matrix<Type, Rows, Cols> operator+=(const Matrix<Type, Rows, Cols>& other);
    Matrix<Type, Rows, Cols> operator-=(const Matrix<Type, Rows, Cols>& other);
    Matrix<Type, Rows, Cols> operator*=(const Matrix<Type, Rows, Cols>& other);

    void set(int row, int col, Type value);
    Type get(int row, int col) const;
    int rows() const;
    int cols() const;
    bool is_square() const;
    int size() const;

    std::array<Type, Rows * Cols> data;
}; // class Matrix

#include "matrix_ops.hpp"
#include "matrix_functions.hpp"

// Constructors

template <typename Type, int Rows, int Cols>
inline Matrix<Type, Rows, Cols>::Matrix()
{
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
inline void Matrix<Type, Rows, Cols>::set(int row, int col, Type value) {
    data[Rows * col + row] = value;
}

template <typename Type, int Rows, int Cols>
inline Type Matrix<Type, Rows, Cols>::get(int row, int col) const{
    return data[Rows * col + row];
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

template <typename Type, int Rows, int Cols>
inline int Matrix<Type, Rows, Cols>::size() const {
    return sizeof(Type) * Rows * Cols;
}
// Matrix Class

// ColVector Class
template<typename Type, int Size>
class ColVector : public Matrix<Type, Size, 1> {
public:
    ColVector<Type, Size> operator*=(const Type& other);
    ColVector<Type, Size> operator+=(const ColVector<Type, Size>& other);
    ColVector<Type, Size> operator-=(const ColVector<Type, Size>& other);

    ColVector<Type, Size + 1> promote(Type new_val) const; 
    ColVector<Type, Size - 1> demote() const; 
    Type& operator[](unsigned int index);

    void set(int pos, Type value);
    Type get(int pos) const;
};

template <typename Type, int Size>
inline void ColVector<Type, Size>::set(int pos, Type value) {
   Matrix<Type, Size, 1>::set(pos, 0, value);
}

template <typename Type, int Size>
inline Type ColVector<Type, Size>::get(int pos) const {
    return Matrix<Type, Size, 1>::get(pos, 0);
}

template <typename Type, int Size>
ColVector<Type, Size + 1> ColVector<Type, Size>::promote(Type new_val) const {
    ColVector<Type, Size + 1> result {};
    for (int i = 0; i < Size; i++){
        result.set(i, get(i));
    }
    result.set(Size, new_val);

    return result;
}

template<typename Type, int Size>
inline ColVector<Type,Size-1> ColVector<Type, Size>::demote() const
{
    ColVector<Type, Size - 1> result {};
    for (int i = 0; i < Size - 1; i++){
        result.set(i, get(i));
    }
    return result;
}

// ColVector class

// RowVector Class
template<typename Type, int Size>
class RowVector : public Matrix<Type, 1, Size> {
public:
    RowVector<Type, Size + 1> promote(Type new_val) const;
    Type& operator[](unsigned int index);

    void set(int pos, Type value);
    Type get(int pos) const;
};

template <typename Type, int Size>
inline void RowVector<Type, Size>::set(int pos, Type value) {
    Matrix<Type, 1, Size>::set(0, pos, value);
}

template <typename Type, int Size>
inline Type RowVector<Type, Size>::get(int pos) const {
    return Matrix<Type, 1, Size>::get(0, pos);
}

template <typename Type, int Size>
RowVector<Type, Size + 1> RowVector<Type, Size>::promote(Type new_val) const {
    RowVector<Type, Size + 1> result {};
    for (int i = 0; i < Size; i++){
        result.set(i, get(i));
    }
    result.set(Size, new_val);
    return result;
}

// RowVector Class

#include "vector_ops.hpp"
#include "vector_functions.hpp"

// Function that need both matrix and vector operations
// Special Functions

namespace mat {
template <typename Type>
inline Matrix<Type, 4, 4> view(
    const ColVector<Type, 3>& u, 
    const ColVector<Type, 3>& v, 
    const ColVector<Type, 3>& n, 
    const ColVector<Type, 3>& e) {
    Matrix<Type, 4, 4> result {};
    result.set(0, 0, u.get(0));
    result.set(0, 1, u.get(1));
    result.set(0, 2, u.get(2));
    result.set(1, 0, v.get(0));
    result.set(1, 1, v.get(1));
    result.set(1, 2, v.get(2));
    result.set(2, 0, n.get(0));
    result.set(2, 1, n.get(1));
    result.set(2, 2, n.get(2));

    result.set(0, 3, -vec::dot(u, e));
    result.set(1, 3, -vec::dot(v, e));
    result.set(2, 3, -vec::dot(n, e));

    result.set(3, 3, (Type) 1);
    return result;
}

inline Matrix<float, 4, 4> ortho(
    float top, float bot, float left, float right, float far, float near) {
    Matrix<float, 4, 4> result {};
    result.set(0, 0, 2.0f/(right - left));
    result.set(1, 1, 2.0f/(top - bot));
    result.set(2, 2, -2.0f/(far - near));

    result.set(0, 3, -(left + right)/(right - left));
    result.set(1, 3, -(bot + top)/(top - bot));
    result.set(2, 3, -(near + far)/(far - near));

    result.set(3, 3, 1.0f);
    return result;
}

inline Matrix<float, 4, 4> perspective(
    float top, float bot, float left, float right, float far, float near) {
    Matrix<float, 4, 4> result {};
    result.set(0, 0, (near*2.0f)/(right - left));
    result.set(1, 1, (near*2.0f)/(top - bot));

    result.set(1, 2, (top + bot)/(top - bot));
    result.set(0, 2, (right + left)/(right - left));
    result.set(2, 2, -(far + near)/(far - near));

    result.set(2, 3, -2.0f*(near * far)/(far - near));
    result.set(3, 2, -1.0f);
    return result;
}

} // namespace mat

// Understandable type aliases

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


