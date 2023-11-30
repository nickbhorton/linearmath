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
    inline Matrix<Type, 2, 1> create(const Type &t1, const Type &t2)
    {
        Matrix<Type, 2, 1> v {};
        v.set(0, 0, t1);
        v.set(1, 0, t2);
        return v;
    }

    template <typename Type>
    inline Matrix<Type, 3, 1> create(const Type &t1, const Type &t2, const Type &t3)
    {
        Matrix<Type, 3, 1> v {};
        v.set(0, 0, t1);
        v.set(1, 0, t2);
        v.set(2, 0, t3);
        return v;
    }

    template <typename Type>
    inline Matrix<Type, 4, 1> create(const Type &t1, const Type &t2, const Type &t3, const Type &t4)
    {
        Matrix<Type, 4, 1> v {};
        v.set(0, 0, t1);
        v.set(1, 0, t2);
        v.set(2, 0, t3);
        v.set(3, 0, t4);
        return v;
    }

    template <typename Type, int Size>
    inline Type dot(const Matrix<Type, 1, Size>& lhs, const Matrix<Type, Size, 1>& rhs)
    {
        auto result = lhs * rhs;
        return result.get(0, 0);
    }

    template <typename Type, int Size>
    inline Type dot(const Matrix<Type, 1, Size>& lhs, const Matrix<Type, 1, Size>& rhs)
    {
        return dot(lhs, rhs.transpose());
    }

    template <typename Type, int Size>
    inline Type dot(const Matrix<Type, Size, 1>& lhs, const Matrix<Type, Size, 1>& rhs)
    {
        return dot(lhs.transpose(), rhs);
    }


    template <typename Type, int Size>
    inline Matrix<Type, Size, 1> cross(const Matrix<Type, Size, 1>& lhs, const Matrix<Type, Size, 1>& rhs)
    {
        return vec::create(
            lhs.get(1, 0) * rhs.get(2, 0) - lhs.get(2, 0) * rhs.get(1, 0),
          - lhs.get(0, 0) * rhs.get(2, 0) + lhs.get(2, 0) * rhs.get(0, 0),
            lhs.get(0, 0) * rhs.get(1, 0) - lhs.get(1, 0) * rhs.get(0, 0)
        );
    }

    template <typename Type, int Size>
    inline Matrix<Type, 1, Size> cross(const Matrix<Type, 1, Size>& lhs, const Matrix<Type, 1, Size>& rhs)
    {
        return cross(lhs.transpose(), rhs.transpose()).transpose();
    }

    template <typename Type, int Size>
    inline Type length(const Matrix<Type, Size, 1>& target)
    {
        return std::sqrt(std::pow(target.get(0, 0), 2) + std::pow(target.get(1, 0), 2) + std::pow(target.get(2, 0), 2));
    }

    template <typename Type, int Size>
    inline Type length(const Matrix<Type, 1, Size>& target)
    {
        return vec::length(target.transpose());
    }

    template <typename Type, int Size>
    inline Matrix<Type, Size, 1> normalize(const Matrix<Type, Size, 1>& target)
    {
        return ((Type)1/vec::length(target)) * target;
    }
}

#endif