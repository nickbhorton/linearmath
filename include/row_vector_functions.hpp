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

template<typename Type, int Size>
inline RowVector<Type,Size-1> RowVector<Type, Size>::demote() const
{
    RowVector<Type, Size - 1> result {};
    for (int i = 0; i < Size - 1; i++){
        result.set(i, get(i));
    }
    return result;
}

namespace rvec{
    template <typename Type>
    inline RowVector<Type, 2> create(const Type &t1, const Type &t2)
    {
        RowVector<Type, 2> v {};
        v.set(0, t1);
        v.set(1, t2);
        return v;
    }

    template <typename Type>
    inline RowVector<Type, 3> create(const Type &t1, const Type &t2, const Type &t3)
    {
        RowVector<Type, 3> v {};
        v.set(0, t1);
        v.set(1, t2);
        v.set(2, t3);
        return v;
    }

    template <typename Type>
    inline RowVector<Type, 4> create(const Type &t1, const Type &t2, const Type &t3, const Type &t4)
    {
        RowVector<Type, 4> v {};
        v.set(0, t1);
        v.set(1, t2);
        v.set(2, t3);
        v.set(3, t4);
        return v;
    }

    template <typename Type, int Size>
    inline Type dot(const RowVector<Type, Size>& lhs, const RowVector<Type, Size>& rhs)
    {
        auto result = lhs * rhs.transpose();
        return result.get(0, 0);
    }

    template <typename Type>
    inline RowVector<Type, 3> cross(const RowVector<Type, 3>& lhs, const RowVector<Type, 3>& rhs)
    {
        return rvec::create(
            lhs.get(1) * rhs.get(2) - lhs.get(2) * rhs.get(1),
          - lhs.get(0) * rhs.get(2) + lhs.get(2) * rhs.get(0),
            lhs.get(0) * rhs.get(1) - lhs.get(1) * rhs.get(0)
        );
    }

    template <typename Type, int Size>
    inline float length(const RowVector<Type, Size>& target)
    {
        Type sum = (Type) 0;
        for (int i = 0; i < Size; i++){
            sum += std::pow(target.get(i), 2);
        }
        return std::sqrt(sum);
    }

    template <int Size>
    inline RowVector<float, Size> normalize(const RowVector<float, Size>& target)
    {
        float len = rvec::length(target);
        if (len == 0.0f){
            return RowVector<float, Size>{};
        }
        return ((float)1/len) * target;
    }
} // namespace vec

#endif