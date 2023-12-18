#ifndef ROW_VECTOR_HEADER
#define ROW_VECTOR_HEADER

// RowVector Class
template<typename Type, int Size>
class RowVector : public Matrix<Type, 1, Size> {
public:
    RowVector<Type, Size> operator*=(const Type& other);
    RowVector<Type, Size> operator/=(const Type& other);
    RowVector<Type, Size> operator+=(const RowVector<Type, Size>& other);
    RowVector<Type, Size> operator-=(const RowVector<Type, Size>& other);

    RowVector<Type, Size + 1> promote(Type new_val) const;
    RowVector<Type, Size - 1> demote() const; 
    Type& operator[](unsigned int index);

    void set(int pos, Type value);
    Type get(int pos) const;
};

// Binary
template <typename Type, int Size>
RowVector<Type, Size> operator*(const Matrix<Type, Size, Size>& lhs, const Matrix<Type, 1, Size>& rhs);
template <typename Type, int Size>
RowVector<Type, Size> operator-(const Matrix<Type, 1, Size>& lhs, const Matrix<Type, 1, Size>& rhs);
template <typename Type, int Size>
RowVector<Type, Size> operator+(const Matrix<Type, 1, Size>& lhs, const Matrix<Type, 1, Size>& rhs);
template <typename Type, int Size>
RowVector<Type, Size> operator*(const Type& lhs, const Matrix<Type, 1, Size>& rhs);
template <typename Type, int Size>
RowVector<Type, Size> operator*(const Matrix<Type, 1, Size>& lhs, const Type& rhs);
template <typename Type, int Size>
RowVector<Type, Size> operator/(const Matrix<Type, 1, Size>& lhs, const Type& rhs);
// Unary
template <typename Type, int Size>
RowVector<Type, Size> operator-(const Matrix<Type, 1, Size>& target);
template <typename Type, int Size>
RowVector<Type, Size> operator+(const Matrix<Type, 1, Size>& target);

#include "row_vector_operators.hpp"
#include "row_vector_functions.hpp"


#endif