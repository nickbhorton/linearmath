#ifndef COLUMN_VECTOR_HEADER
#define COLUMN_VECTOR_HEADER

template<typename Type, int Size>
class ColVector : public Matrix<Type, Size, 1> {
public:
    ColVector<Type, Size> operator*=(const Type& other);
    ColVector<Type, Size> operator/=(const Type& other);
    ColVector<Type, Size> operator+=(const ColVector<Type, Size>& other);
    ColVector<Type, Size> operator-=(const ColVector<Type, Size>& other);

    ColVector<Type, Size + 1> promote(Type new_val) const; 
    ColVector<Type, Size - 1> demote() const; 
    Type& operator[](unsigned int index);

    void set(int pos, Type value);
    Type get(int pos) const;

    constexpr Type x() const noexcept {
        if constexpr (Size >= 1){
            return this->data[0];
        }
        return (Type) 0;
    }
    constexpr Type y() const noexcept {
        if constexpr (Size >= 2){
            return this->data[1];
        }
        return (Type) 0;
    }
    constexpr Type z() const noexcept {
        if constexpr (Size >= 3){
            return this->data[2];
        }
        return (Type) 0;
    }
    constexpr Type w() const noexcept {
        if constexpr (Size >= 4){
            return this->data[3];
        }
        return (Type) 0;
    }
}; // ColVector

// binary
template <typename Type, int Size>
ColVector<Type, Size> operator*(const Matrix<Type, Size, Size>& lhs, const Matrix<Type, Size, 1>& rhs);
template <typename Type, int Size>
ColVector<Type, Size> operator-(const Matrix<Type, Size, 1>& lhs, const Matrix<Type, Size, 1>& rhs);
template <typename Type, int Size>
ColVector<Type, Size> operator+(const Matrix<Type, Size, 1>& lhs, const Matrix<Type, Size, 1>& rhs);
template <typename Type, int Size>
ColVector<Type, Size> operator*(const Type& lhs, const Matrix<Type, Size, 1>& rhs);
template <typename Type, int Size>
ColVector<Type, Size> operator*(const Matrix<Type, Size, 1>& lhs, const Type& rhs);
template <typename Type, int Size>
ColVector<Type, Size> operator/(const Matrix<Type, Size, 1>& lhs, const Type& rhs);
template <typename Type, int Size>
bool operator==(const ColVector<Type, Size>& lhs, const ColVector<Type, Size>& rhs);
template <typename Type, int Size>
bool operator!=(const ColVector<Type, Size>& lhs, const ColVector<Type, Size>& rhs);
// unary
template <typename Type, int Size>
ColVector<Type, Size> operator-(const Matrix<Type, Size, 1>& target);
template <typename Type, int Size>
ColVector<Type, Size> operator+(const Matrix<Type, Size, 1>& target);
template <typename Type, int Size>
std::ostream& operator<<(std::ostream& os, const ColVector<Type, Size>& target);

#include "column_vector_operators.hpp"
#include "column_vector_functions.hpp"

#endif