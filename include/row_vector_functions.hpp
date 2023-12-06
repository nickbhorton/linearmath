#ifndef ROW_VECTOR_FUNCTIONS_HEADER
#define ROW_VECTOR_FUNCTIONS_HEADER

#include "class_forward_declaration.hpp"

// RowVector members
template <typename Type, int Size>
inline void RowVector<Type, Size>::set(int pos, Type value) {
    Matrix<Type, 1, Size>::set(0, pos, value);
}

template <typename Type, int Size>
inline Type RowVector<Type, Size>::get(int pos) const {
    return Matrix<Type, 1, Size>::get(0, pos);
}

template <typename Type, int Size>
RowVector<Type, Size + 1> RowVector<Type, Size>::promote(Type new_val) const {
    RowVector<Type, Size + 1> result {};
    for (int i = 0; i < Size; i++){
        result.set(i, get(i));
    }
    result.set(Size, new_val);
    return result;
}

namespace vec{
    template <int Size>
    inline RowVector<float, Size> normalize(const RowVector<float, Size>& target)
    {
        float len = vec::length(target);
        if (len == 0.0f){
            return RowVector<float, Size>{};
        }
        return ((float)1/len) * target;
    }
} // namespace vec

#endif