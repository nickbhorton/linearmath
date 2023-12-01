#ifndef VECTOR_FUNCTIONS_HEADER
#define VECTOR_FUNCTIONS_HEADER

#ifndef PROCESSED
#include "matrix.hpp"
#endif

namespace vec{
    /** \brief by default creates a column vector. Transpose if a row vector is wanted
      * 
      */
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
    inline RowVector<float, Size> normalize(const RowVector<float, Size>& target)
    {
        float len = vec::length(target);
        if (len == 0.0f){
            return RowVector<float, Size>{};
        }
        return ((float)1/len) * target;
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