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

#include "matrix_operators.hpp"
#include "matrix_functions.hpp"
#include "column_vector.hpp"
#include "row_vector.hpp"

#include "graphics_functions.hpp"

// type aliases

// Matrix aliases

typedef Matrix<float, 2, 2> mat2f;
typedef Matrix<float, 3, 3> mat3f;
typedef Matrix<float, 4, 4> mat4f;

typedef Matrix<double, 2, 2> mat2d;
typedef Matrix<double, 3, 3> mat3d;
typedef Matrix<double, 4, 4> mat4d;

typedef Matrix<int, 2, 2> mat2i;
typedef Matrix<int, 3, 3> mat3i;
typedef Matrix<int, 4, 4> mat4i;

typedef Matrix<uint8_t, 2, 2> mat2u8;
typedef Matrix<uint8_t, 3, 3> mat3u8;
typedef Matrix<uint8_t, 4, 4> mat4u8;

typedef Matrix<uint16_t, 2, 2> mat2u16;
typedef Matrix<uint16_t, 3, 3> mat3u16;
typedef Matrix<uint16_t, 4, 4> mat4u16;

typedef Matrix<uint32_t, 2, 2> mat2u32;
typedef Matrix<uint32_t, 3, 3> mat3u32;
typedef Matrix<uint32_t, 4, 4> mat4u32;

typedef Matrix<uint64_t, 2, 2> mat2u64;
typedef Matrix<uint64_t, 3, 3> mat3u64;
typedef Matrix<uint64_t, 4, 4> mat4u64;

typedef Matrix<int8_t, 2, 2> mat2i8;
typedef Matrix<int8_t, 3, 3> mat3i8;
typedef Matrix<int8_t, 4, 4> mat4i8;

typedef Matrix<int16_t, 2, 2> mat2i16;
typedef Matrix<int16_t, 3, 3> mat3i16;
typedef Matrix<int16_t, 4, 4> mat4i16;

typedef Matrix<int32_t, 2, 2> mat2i32;
typedef Matrix<int32_t, 3, 3> mat3i32;
typedef Matrix<int32_t, 4, 4> mat4i32;

typedef Matrix<int64_t, 2, 2> mat2i64;
typedef Matrix<int64_t, 3, 3> mat3i64;
typedef Matrix<int64_t, 4, 4> mat4i64;


// ColVector aliases

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

// RowVector aliases

typedef RowVector<float, 2> rvec2f;
typedef RowVector<float, 3> rvec3f;
typedef RowVector<float, 4> rvec4f;

typedef RowVector<double, 2> rvec2d;
typedef RowVector<double, 3> rvec3d;
typedef RowVector<double, 4> rvec4d;

typedef RowVector<int, 2> rvec2i;
typedef RowVector<int, 3> rvec3i;
typedef RowVector<int, 4> rvec4i;

typedef RowVector<uint8_t, 2> rvec2u8;
typedef RowVector<uint8_t, 3> rvec3u8;
typedef RowVector<uint8_t, 4> rvec4u8;

typedef RowVector<uint16_t, 2> rvec2u16;
typedef RowVector<uint16_t, 3> rvec3u16;
typedef RowVector<uint16_t, 4> rvec4u16;

typedef RowVector<uint32_t, 2> rvec2u32;
typedef RowVector<uint32_t, 3> rvec3u32;
typedef RowVector<uint32_t, 4> rvec4u32;

typedef RowVector<uint64_t, 2> rvec2u64;
typedef RowVector<uint64_t, 3> rvec3u64;
typedef RowVector<uint64_t, 4> rvec4u64;

typedef RowVector<int8_t, 2> rvec2i8;
typedef RowVector<int8_t, 3> rvec3i8;
typedef RowVector<int8_t, 4> rvec4i8;

typedef RowVector<int16_t, 2> rvec2i16;
typedef RowVector<int16_t, 3> rvec3i16;
typedef RowVector<int16_t, 4> rvec4i16;

typedef RowVector<int32_t, 2> rvec2i32;
typedef RowVector<int32_t, 3> rvec3i32;
typedef RowVector<int32_t, 4> rvec4i32;

typedef RowVector<int64_t, 2> rvec2i64;
typedef RowVector<int64_t, 3> rvec3i64;
typedef RowVector<int64_t, 4> rvec4i64;

#endif


