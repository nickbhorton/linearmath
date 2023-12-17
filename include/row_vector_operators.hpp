#ifndef ROW_VECTOR_OPS_HEADER
#define ROW_VECTOR_OPS_HEADER

#include "class_forward_declaration.hpp"

// Indexing operator
template <typename Type, int Size>
inline Type& RowVector<Type, Size>::operator[](unsigned int index){
    return this->data[index];
}

//
// Unary operators
//

// Unary minus
template <typename Type, int Size>
RowVector<Type, Size> operator-(const Matrix<Type, 1, Size>& target) {
    RowVector<Type, Size> result {};
    for (int i = 0; i < Size; i++){
        result.set(i, -target.get(0, i));
    }
    return result;
}

// Unary plus
template <typename Type, int Size>
RowVector<Type, Size> operator+(const Matrix<Type, 1, Size>& target) {
    return target;
}

//
// Binary Operator
//

// RowVector * (Square)Matrix
template <typename Type, int Size>
RowVector<Type, Size> operator*(const Matrix<Type, 1, Size>& lhs, const Matrix<Type, Size, Size>& rhs) {
    RowVector<Type, Size> result {};
    for (int j = 0; j < Size; j++){
        Type sum = 0;
        for (int k = 0; k < Size; k++) {
            sum += lhs.get(0, k) * rhs.get(k, j);
        }
        result.set(j, sum);
    }
    return result;
}

// Binary plus
template <typename Type, int Size>
RowVector<Type, Size> operator-(const Matrix<Type, 1, Size>& lhs, const Matrix<Type, 1, Size>& rhs) {
    RowVector<Type, Size> result {};
    for (int i = 0; i < Size; i++){
        result.set(i, lhs.get(i, 0) - rhs.get(i, 0));
    }
    return result;
}

// Binary minus
template <typename Type, int Size>
RowVector<Type, Size> operator+(const Matrix<Type, 1, Size>& lhs, const Matrix<Type, 1, Size>& rhs) {
    RowVector<Type, Size> result {};
    for (int i = 0; i < Size; i++){
        result.set(i, lhs.get(i, 0) + rhs.get(i, 0));
    }
    return result;
}

// Scalar multiplication LHS
template <typename Type, int Size>
RowVector<Type, Size> operator*(const Type& lhs, const Matrix<Type, 1, Size>& rhs) {
    RowVector<Type, Size> result {};
    for (int i = 0; i < Size; i++){
        result.set(i, lhs * rhs.get(i, 0));
    }
    return result;
}

// Scalar multiplication RHS
template <typename Type, int Size>
RowVector<Type, Size> operator*(const Matrix<Type, 1, Size>& lhs, const Type& rhs) {
    RowVector<Type, Size> result {};
    for (int i = 0; i < Size; i++){
        result.set(i, lhs.get(i, 0) * rhs);
    }
    return result;
}

//
// Assignment operators
//

// Scalar multiplication assignment
template<typename Type, int Size>
inline RowVector<Type,Size> RowVector<Type, Size>::operator*=(const Type & other)
{
    *this = *this * other;
    return *this;
}

// Addition assignment
template<typename Type, int Size>
inline RowVector<Type,Size> RowVector<Type, Size>::operator+=(const RowVector<Type, Size> & other)
{
    *this = *this + other;
    return *this;
}

// Subtraction assignment
template<typename Type, int Size>
inline RowVector<Type,Size> RowVector<Type, Size>::operator-=(const RowVector<Type, Size> & other)
{
    *this = *this - other;
    return *this;
}

#endif