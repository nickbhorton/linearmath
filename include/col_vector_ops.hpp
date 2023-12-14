#ifndef COL_VECTOR_OPS_HEADER
#define COL_VECTOR_OPS_HEADER

#include "class_forward_declaration.hpp"

// Indexing operator
template <typename Type, int Size>
inline Type& ColVector<Type, Size>::operator[](unsigned int index){
    return this->data[index];
}

//
// Unary operators
//

// Unary minus
template <typename Type, int Size>
ColVector<Type, Size> operator-(const Matrix<Type, Size, 1>& target) {
    ColVector<Type, Size> result {};
    for (int i = 0; i < Size; i++){
        result.set(i, -target.get(i, 0));
    }
    return result;
}

// Unary plus
template <typename Type, int Size>
ColVector<Type, Size> operator+(const Matrix<Type, Size, 1>& target) {
    return target;
}

//
// Binary Operators 
//

// (Square)Matrix * ColVector
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

// Binary plus
template <typename Type, int Size>
ColVector<Type, Size> operator-(const Matrix<Type, Size, 1>& lhs, const Matrix<Type, Size, 1>& rhs) {
    ColVector<Type, Size> result {};
    for (int i = 0; i < Size; i++){
        result.set(i, lhs.get(i, 0) - rhs.get(i, 0));
    }
    return result;
}

// Binary minus
template <typename Type, int Size>
ColVector<Type, Size> operator+(const Matrix<Type, Size, 1>& lhs, const Matrix<Type, Size, 1>& rhs) {
    ColVector<Type, Size> result {};
    for (int i = 0; i < Size; i++){
        result.set(i, lhs.get(i, 0) + rhs.get(i, 0));
    }
    return result;
}

// Scalar multiplication LHS
template <typename Type, int Size>
ColVector<Type, Size> operator*(const Type& lhs, const Matrix<Type, Size, 1>& rhs) {
    ColVector<Type, Size> result {};
    for (int i = 0; i < Size; i++){
        result.set(i, lhs * rhs.get(i, 0));
    }
    return result;
}

// Scalar multiplication RHS
template <typename Type, int Size>
ColVector<Type, Size> operator*(const Matrix<Type, Size, 1>& lhs, const Type& rhs) {
    ColVector<Type, Size> result {};
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
inline ColVector<Type,Size> ColVector<Type, Size>::operator*=(const Type & other)
{
    *this = *this * other;
    return *this;
}

// Addition assignment
template<typename Type, int Size>
inline ColVector<Type,Size> ColVector<Type, Size>::operator+=(const ColVector<Type, Size> & other)
{
    *this = *this + other;
    return *this;
}

// Subtraction assignment
template<typename Type, int Size>
inline ColVector<Type,Size> ColVector<Type, Size>::operator-=(const ColVector<Type, Size> & other)
{
    *this = *this - other;
    return *this;
}

#endif