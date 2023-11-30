#ifndef VECTOR_OPS_HEADER
#define VECTOR_OPS_HEADER

#ifndef PROCESSED
#include "matrix.hpp"
#endif


template <typename Type, int Size>
inline Type& ColVector<Type, Size>::operator[](unsigned int index){
    return this->data[index];
}

template <typename Type, int Size>
inline Type& RowVector<Type, Size>::operator[](unsigned int index){
    return this->data[index];
}

// (ColVector and RowVector) Matrix Multiplication

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