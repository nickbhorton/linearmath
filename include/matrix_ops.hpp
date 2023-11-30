#ifndef MATRIX_OPS_HEADER
#define MATRIX_OPS_HEADER

#ifndef PROCESSED
#include "matrix.hpp"
#endif

template <typename Type, int RowsLHS, int RowsRHSColsLHS, int ColsRHS>
Matrix<Type, RowsLHS, ColsRHS> operator*(const Matrix<Type, RowsLHS, RowsRHSColsLHS>& lhs, const Matrix<Type, RowsRHSColsLHS, ColsRHS>& rhs) {
    Matrix<Type, RowsLHS, ColsRHS> result {};
    for (int i = 0; i < RowsLHS; i++){
        for (int j = 0; j < ColsRHS; j++){
            Type sum = 0;
            for (int k = 0; k < RowsRHSColsLHS; k++) {
                sum += lhs.get(i, k) * rhs.get(k, j);
            }
            result.set(i, j, sum);
        }
    }
    return result;
}

template <typename Type, int Rows, int Cols>
Matrix<Type, Rows, Cols> operator*(const Type lhs, const Matrix<Type, Rows, Cols>& rhs) {
    Matrix<Type, Rows, Cols> result {};
    for (int i = 0; i < Rows; i++){
        for (int j = 0; j < Cols; j++){
            result.set(i, j, lhs * rhs.get(i, j));
        }
    }
    return result;
}

template <typename Type, int Rows, int Cols>
Matrix<Type, Rows, Cols> operator*(const Matrix<Type, Rows, Cols>& lhs, const Type rhs) {
    Matrix<Type, Rows, Cols> result {};
    for (int i = 0; i < Rows; i++){
        for (int j = 0; j < Cols; j++){
            result.set(i, j, lhs.get(i, j) * rhs);
        }
    }
    return result;
}

template <typename Type, int Rows, int Cols>
Matrix<Type, Rows, Cols> operator/(const Matrix<Type, Rows, Cols>& lhs, const Type rhs) {
    Matrix<Type, Rows, Cols> result {};
    for (int i = 0; i < Rows; i++){
        for (int j = 0; j < Cols; j++){
            if (rhs != (Type) 0){
                result.set(i, j, lhs.get(i, j) / rhs);
            }
            else {
                // Default to zero
                result.set(i, j, (Type) 0);
            }
        }
    }
    return result;
}


template <typename Type, int Rows, int Cols>
Matrix<Type, Rows, Cols> operator+(const Matrix<Type, Rows, Cols>& lhs, const Matrix<Type, Rows, Cols>& rhs) {
    Matrix<Type, Rows, Cols> result {};
    for (int i = 0; i < Rows; i++){
        for (int j = 0; j < Cols; j++){
            result.set(i, j, lhs.get(i, j) + rhs.get(i, j));
        }
    }
    return result;
}

template <typename Type, int Rows, int Cols>
Matrix<Type, Rows, Cols> operator-(const Matrix<Type, Rows, Cols>& lhs, const Matrix<Type, Rows, Cols>& rhs) {
    Matrix<Type, Rows, Cols> result {};
    for (int i = 0; i < Rows; i++){
        for (int j = 0; j < Cols; j++){
            result.set(i, j, lhs.get(i, j) - rhs.get(i, j));
        }
    }
    return result;
}

template <typename Type, int Rows, int Cols>
bool operator==(const Matrix<Type, Rows, Cols>& lhs, const Matrix<Type, Rows, Cols>& rhs) {
    for (int i = 0; i < Rows; i++){
        for (int j = 0; j < Cols; j++){
            if (lhs.get(i, j) != rhs.get(i, j)) {
                return false;
            }
        }
    }
    return true;
}

template <typename Type, int Rows, int Cols>
bool operator!=(const Matrix<Type, Rows, Cols>& lhs, const Matrix<Type, Rows, Cols>& rhs) {
    return !(lhs == rhs);
}

template <typename Type, int Rows, int Cols>
Matrix<Type, Rows, Cols> Matrix<Type, Rows, Cols>::operator+=(const Matrix<Type, Rows, Cols>& other) {
    this = this + other;
}

template <typename Type, int Rows, int Cols>
Matrix<Type, Rows, Cols> Matrix<Type, Rows, Cols>::operator-=(const Matrix<Type, Rows, Cols>& other) {
    this = this - other;
}

template <typename Type, int Rows, int Cols>
Matrix<Type, Rows, Cols> Matrix<Type, Rows, Cols>::operator*=(const Matrix<Type, Rows, Cols>& other) {
    this = this * other;
}

template <typename Type, int Rows, int Cols>
std::ostream& operator<<(std::ostream& os, const Matrix<Type, Rows, Cols>& m){
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++){
            os << m.get(i, j) << " ";
        }
        if (i != Rows - 1){
            os << "\n";
        }
    }
    return os;
}

#endif