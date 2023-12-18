#ifndef COL_VECTOR_OPS_HEADER
#define COL_VECTOR_OPS_HEADER

#include "class_forward_declaration.hpp"

template <typename Type, int Size>
inline Type& ColVector<Type, Size>::operator[](unsigned int index){
    return this->data[index];
}

// unary 

template <typename Type, int Size>
ColVector<Type, Size> operator-(const Matrix<Type, Size, 1>& target) {
    ColVector<Type, Size> result {};
    for (int i = 0; i < Size; i++){
        result.set(i, -target.get(i, 0));
    }
    return result;
}

template <typename Type, int Size>
ColVector<Type, Size> operator+(const Matrix<Type, Size, 1>& target) {
    return target.col(0);
}

template <typename Type, int Size>
std::ostream& operator<<(std::ostream& os, const ColVector<Type, Size>& target){
    os << "(";
    for (int i = 0; i < Size - 1; i++){
        os << target.get(i) << ", ";
    }
    os << target.get(Size - 1) << ")";
    return os;
}

// binary 

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

template <typename Type, int Size>
ColVector<Type, Size> operator*(const Type& lhs, const Matrix<Type, Size, 1>& rhs) {
    ColVector<Type, Size> result {};
    for (int i = 0; i < Size; i++){
        result.set(i, lhs * rhs.get(i, 0));
    }
    return result;
}

template <typename Type, int Size>
ColVector<Type, Size> operator*(const Matrix<Type, Size, 1>& lhs, const Type& rhs) {
    ColVector<Type, Size> result {};
    for (int i = 0; i < Size; i++){
        result.set(i, lhs.get(i, 0) * rhs);
    }
    return result;
}

template <typename Type, int Size>
ColVector<Type, Size> operator/(const Matrix<Type, Size, 1>& lhs, const Type& rhs) {
    ColVector<Type, Size> result {};
    for (int i = 0; i < Size; i++){
        result.set(i, lhs.get(i, 0) / rhs);
    }
    return result;
}

template <typename Type, int Size>
bool operator==(const ColVector<Type, Size>& lhs, const ColVector<Type, Size>& rhs) {
    for (int i = 0; i < Size; i++){
        if (lhs.get(i) != rhs.get(i)) {
            return false;
        }
    }
    return true;
}
template <typename Type, int Size>
bool operator!=(const ColVector<Type, Size>& lhs, ColVector<Type, Size>& rhs) {
    for (int i = 0; i < Size; i++){
        if (lhs.get(i) != rhs.get(i)) {
            return true;
        }
    }
    return false;
}

// assignment

template<typename Type, int Size>
inline ColVector<Type,Size> ColVector<Type, Size>::operator*=(const Type & other)
{
    *this = *this * other;
    return *this;
}

template<typename Type, int Size>
inline ColVector<Type,Size> ColVector<Type, Size>::operator/=(const Type & other)
{
    *this = *this / other;
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

#endif