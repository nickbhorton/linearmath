#ifndef COLUMN_VECTOR_HEADER
#define COLUMN_VECTOR_HEADER

// ColVector Class
template<typename Type, int Size>
class ColVector : public Matrix<Type, Size, 1> {
public:
    ColVector<Type, Size> operator*=(const Type& other);
    ColVector<Type, Size> operator+=(const ColVector<Type, Size>& other);
    ColVector<Type, Size> operator-=(const ColVector<Type, Size>& other);

    ColVector<Type, Size + 1> promote(Type new_val) const; 
    ColVector<Type, Size - 1> demote() const; 
    Type& operator[](unsigned int index);

    void set(int pos, Type value);
    Type get(int pos) const;
};

#include "column_vector_operators.hpp"
#include "column_vector_functions.hpp"

#endif