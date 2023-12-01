#ifndef VECTOR_OPS_HEADER
#define VECTOR_OPS_HEADER

#ifndef PROCESSED
#include "matrix.hpp"
#endif

// ColVector Ops

template <typename Type, int Size>
inline Type& ColVector<Type, Size>::operator[](unsigned int index){
    return this->data[index];
}

// Unary operators [op ColVector]

template <typename Type, int Size>
ColVector<Type, Size> operator-(const Matrix<Type, Size, 1>& target) {
    ColVector<Type, Size> result {};
    for (int i = 0; i < Size; i++){
        result.set(i, -target.get(i, 0));
    }
    return result;
}

// Binary Operator [(Square)Matrix op ColVector]

template <typename Type, int Size>
ColVector<Type, Size> operator*(const Matrix<Type, Size, Size>& lhs, const Matrix<Type, Size, 1>& rhs) {
    ColVector<Type, Size> result {};
    for (int i = 0; i < Size; i++){
        Type sum = 0;
        for (int k = 0; k < Size; k++) {
            sum += lhs.get(i, k) * rhs.get(k, 0);
        }
        result.set(i, sum);
    }
    return result;
}

// Binary Operator [ColVector op ColVector]

template <typename Type, int Size>
ColVector<Type, Size> operator-(const Matrix<Type, Size, 1>& lhs, const Matrix<Type, Size, 1>& rhs) {
    ColVector<Type, Size> result {};
    for (int i = 0; i < Size; i++){
        result.set(i, lhs.get(i, 0) - rhs.get(i, 0));
    }
    return result;
}

template <typename Type, int Size>
ColVector<Type, Size> operator+(const Matrix<Type, Size, 1>& lhs, const Matrix<Type, Size, 1>& rhs) {
    ColVector<Type, Size> result {};
    for (int i = 0; i < Size; i++){
        result.set(i, lhs.get(i, 0) + rhs.get(i, 0));
    }
    return result;
}

// Binary Operator [Type op ColVector]

template <typename Type, int Size>
ColVector<Type, Size> operator*(const Type& lhs, const Matrix<Type, Size, 1>& rhs) {
    ColVector<Type, Size> result {};
    for (int i = 0; i < Size; i++){
        result.set(i, lhs * rhs.get(i, 0));
    }
    return result;
}

// Binary Operator [ColVector op Type]

template <typename Type, int Size>
ColVector<Type, Size> operator*(const Matrix<Type, Size, 1>& lhs, const Type& rhs) {
    ColVector<Type, Size> result {};
    for (int i = 0; i < Size; i++){
        result.set(i, lhs.get(i, 0) * rhs);
    }
    return result;
}

// Assignment operators

template<typename Type, int Size>
inline ColVector<Type,Size> ColVector<Type, Size>::operator*=(const Type & other)
{
    *this = *this * other;
    return *this;
}

template<typename Type, int Size>
inline ColVector<Type,Size> ColVector<Type, Size>::operator+=(const ColVector<Type, Size> & other)
{
    *this = *this + other;
    return *this;
}

template<typename Type, int Size>
inline ColVector<Type,Size> ColVector<Type, Size>::operator-=(const ColVector<Type, Size> & other)
{
    *this = *this - other;
    return *this;
}

// RowVector Ops

template <typename Type, int Size>
inline Type& RowVector<Type, Size>::operator[](unsigned int index){
    return this->data[index];
}

// Binary Operator [RowVector op (Square)Matrix]

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

#endif