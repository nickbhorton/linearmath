#ifndef COL_VECTOR_FUNCTIONS_HEADER
#define COL_VECTOR_FUNCTIONS_HEADER

#include "class_forward_declaration.hpp"

template <typename Type, int Size>
inline void ColVector<Type, Size>::set(int pos, Type value) {
   Matrix<Type, Size, 1>::set(pos, 0, value);
}

template <typename Type, int Size>
inline Type ColVector<Type, Size>::get(int pos) const {
    return Matrix<Type, Size, 1>::get(pos, 0);
}

template <typename Type, int Size>
ColVector<Type, Size + 1> ColVector<Type, Size>::promote(Type new_val) const {
    ColVector<Type, Size + 1> result {};
    for (int i = 0; i < Size; i++){
        result.set(i, get(i));
    }
    result.set(Size, new_val);

    return result;
}

template<typename Type, int Size>
inline ColVector<Type,Size-1> ColVector<Type, Size>::demote() const
{
    ColVector<Type, Size - 1> result {};
    for (int i = 0; i < Size - 1; i++){
        result.set(i, get(i));
    }
    return result;
}

namespace vec{
    template <typename Type>
    inline ColVector<Type, 2> create(const Type &t1, const Type &t2)
    {
        ColVector<Type, 2> v {};
        v.set(0, t1);
        v.set(1, t2);
        return v;
    }

    template <typename Type>
    inline ColVector<Type, 3> create(const Type &t1, const Type &t2, const Type &t3)
    {
        ColVector<Type, 3> v {};
        v.set(0, t1);
        v.set(1, t2);
        v.set(2, t3);
        return v;
    }

    template <typename Type>
    inline ColVector<Type, 4> create(const Type &t1, const Type &t2, const Type &t3, const Type &t4)
    {
        ColVector<Type, 4> v {};
        v.set(0, t1);
        v.set(1, t2);
        v.set(2, t3);
        v.set(3, t4);
        return v;
    }


    template <typename Type, int Size>
    inline Type dot(const ColVector<Type, Size>& lhs, const ColVector<Type, Size>& rhs)
    {
        auto result = lhs.transpose() * rhs;
        return result.get(0, 0);
    }


    template <typename Type>
    inline ColVector<Type, 3> cross(const ColVector<Type, 3>& lhs, const ColVector<Type, 3>& rhs)
    {
        return vec::create(
            lhs.get(1) * rhs.get(2) - lhs.get(2) * rhs.get(1),
          - lhs.get(0) * rhs.get(2) + lhs.get(2) * rhs.get(0),
            lhs.get(0) * rhs.get(1) - lhs.get(1) * rhs.get(0)
        );
    }

    template <typename Type, int Size>
    inline float length(const ColVector<Type, Size>& target)
    {
        Type sum = (Type) 0;
        for (int i = 0; i < Size; i++){
            sum += std::pow(target.get(i), 2);
        }
        return std::sqrt(sum);
    }

    template <int Size>
    inline ColVector<float, Size> normalize(const ColVector<float, Size>& target)
    {
        float len = vec::length(target);
        if (len == 0.0f){
            return ColVector<float, Size>{};
        }
        return ((float)1/len) * target;
    }
}


#endif