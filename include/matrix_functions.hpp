#ifndef MATRIX_FUNCTIONS_HEADER
#define MATRIX_FUNCTIONS_HEADER

#include "class_forward_declaration.hpp"

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
inline ColVector<Type, Rows> Matrix<Type, Rows, Cols>::col(unsigned int i)
{
    ColVector<Type, Rows> result {};
    for (int index = 0; index < Rows; index++) {
        result[index] = get(index, i);
    }
    return result;
}

template <typename Type, int Rows, int Cols>
inline RowVector<Type, Cols> Matrix<Type, Rows, Cols>::row(unsigned int i)
{
    RowVector<Type, Cols> result {};
    for (int index = 0; index < Cols; index++) {
        result[index] = get(i, index);
    }
    return result;
}

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

// Specialized generating functions
namespace mat{
    template <typename Type, int Rows, int Cols>
    inline Matrix<Type, Rows, Cols> identity()
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
    inline Matrix<Type, Rows, Cols> identity(const Type& diag_values)
    {
        Matrix<Type, Rows, Cols> m {};
        for (unsigned int row = 0; row < Rows; row++){
            for (unsigned int col = 0; col < Cols; col++){
                if (row == col)
                {
                    m.set(row, col, diag_values);
                }
            }
        }
        return m;
    }

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
    inline Matrix<Type, 4, 4> create(const Matrix<Type, 4, 1>& v1, const Matrix<Type, 4, 1>& v2, const Matrix<Type, 4, 1>& v3, const Matrix<Type, 4, 1>& v4) {
        Matrix<Type, 4, 4> m {};
        m.set(0, 0, v1.get(0, 0));
        m.set(1, 0, v1.get(1, 0));
        m.set(2, 0, v1.get(2, 0));
        m.set(3, 0, v1.get(3, 0));
        m.set(0, 1, v2.get(0, 0));
        m.set(1, 1, v2.get(1, 0));
        m.set(2, 1, v2.get(2, 0));
        m.set(3, 1, v2.get(3, 0));
        m.set(0, 2, v3.get(0, 0));
        m.set(1, 2, v3.get(1, 0));
        m.set(2, 2, v3.get(2, 0));
        m.set(3, 2, v3.get(3, 0));
        m.set(0, 3, v4.get(0, 0));
        m.set(1, 3, v4.get(1, 0));
        m.set(2, 3, v4.get(2, 0));
        m.set(3, 3, v4.get(3, 0));
        return m;
    }
}

#endif