#ifndef MATRIX_HEADER
#define MATRIX_HEADER

#include "class_forward_declaration.hpp"

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

#include "col_vector_ops.hpp"
#include "col_vector_functions.hpp"

// RowVector Class
template<typename Type, int Size>
class RowVector : public Matrix<Type, 1, Size> {
public:
    RowVector<Type, Size> operator*=(const Type& other);
    RowVector<Type, Size> operator+=(const RowVector<Type, Size>& other);
    RowVector<Type, Size> operator-=(const RowVector<Type, Size>& other);

    RowVector<Type, Size + 1> promote(Type new_val) const;
    RowVector<Type, Size - 1> demote() const; 
    Type& operator[](unsigned int index);

    void set(int pos, Type value);
    Type get(int pos) const;
};

#include "row_vector_ops.hpp"
#include "row_vector_functions.hpp"

#include "graphics_functions.hpp"

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

typedef ColVector<double, 2> vec2d;
typedef ColVector<double, 3> vec3d;
typedef ColVector<double, 4> vec4d;

typedef ColVector<int, 2> vec2i;
typedef ColVector<int, 3> vec3i;
typedef ColVector<int, 4> vec4i;

typedef ColVector<uint8_t, 2> vec2u8;
typedef ColVector<uint8_t, 3> vec3u8;
typedef ColVector<uint8_t, 4> vec4u8;

typedef ColVector<uint16_t, 2> vec2u16;
typedef ColVector<uint16_t, 3> vec3u16;
typedef ColVector<uint16_t, 4> vec4u16;

typedef ColVector<uint32_t, 2> vec2u32;
typedef ColVector<uint32_t, 3> vec3u32;
typedef ColVector<uint32_t, 4> vec4u32;

typedef ColVector<uint64_t, 2> vec2u64;
typedef ColVector<uint64_t, 3> vec3u64;
typedef ColVector<uint64_t, 4> vec4u64;

typedef ColVector<int8_t, 2> vec2i8;
typedef ColVector<int8_t, 3> vec3i8;
typedef ColVector<int8_t, 4> vec4i8;

typedef ColVector<int16_t, 2> vec2i16;
typedef ColVector<int16_t, 3> vec3i16;
typedef ColVector<int16_t, 4> vec4i16;

typedef ColVector<int32_t, 2> vec2i32;
typedef ColVector<int32_t, 3> vec3i32;
typedef ColVector<int32_t, 4> vec4i32;

typedef ColVector<int64_t, 2> vec2i64;
typedef ColVector<int64_t, 3> vec3i64;
typedef ColVector<int64_t, 4> vec4i64;

typedef RowVector<float, 2> rvec2f;
typedef RowVector<float, 3> rvec3f;
typedef RowVector<float, 4> rvec4f;

typedef RowVector<int, 2> rvec2i;
typedef RowVector<int, 3> rvec3i;
typedef RowVector<int, 4> rvec4i;

#endif


