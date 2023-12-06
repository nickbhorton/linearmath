#ifndef ROW_VECTOR_OPS_HEADER
#define ROW_VECTOR_OPS_HEADER

#include "class_forward_declaration.hpp"

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