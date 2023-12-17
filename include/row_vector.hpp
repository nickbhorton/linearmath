#ifndef ROW_VECTOR_HEADER
#define ROW_VECTOR_HEADER

// RowVector Class
template<typename Type, int Size>
class RowVector : public Matrix<Type, 1, Size> {
public:
    RowVector<Type, Size> operator*=(const Type& other);
    RowVector<Type, Size> operator+=(const RowVector<Type, Size>& other);
    RowVector<Type, Size> operator-=(const RowVector<Type, Size>& other);

    RowVector<Type, Size + 1> promote(Type new_val) const;
    RowVector<Type, Size - 1> demote() const; 
    Type& operator[](unsigned int index);

    void set(int pos, Type value);
    Type get(int pos) const;
};

#include "row_vector_operators.hpp"
#include "row_vector_functions.hpp"


#endif