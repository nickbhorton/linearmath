#ifndef MATRIX_FUNCTIONS_HEADER
#define MATRIX_FUNCTIONS_HEADER

#ifndef PROCESSED
#include "matrix.hpp"
#endif

namespace mat{
    template <typename Type>
    Type det(Matrix<Type, 2, 2> m) {
        return m.get(0, 0) * m.get(1, 1) - m.get(0, 1) * m.get(1, 0);
    }

    template <typename Type>
    Type det(Matrix<Type, 3, 3> m) {
        return det(m.minor(0, 0)) - det(m.minor(1, 0)) + det(m.minor(2, 0));
    }

    template <typename Type>
    Type det(Matrix<Type, 4, 4> m) {
        return det(m.minor(0, 0)) - det(m.minor(1, 0)) + det(m.minor(2, 0)) + det(m.minor(3, 0));
    }

    template <typename Type, int Rows, int Cols>
    inline Matrix<Type, Rows, Cols> identity()
    {
        Matrix<Type, Rows, Cols> m {};
        for (unsigned int row = 0; row < Rows; row++){
            for (unsigned int col = 0; col < Cols; col++){
                if (row == col)
                {
                    m.set(row, col, 1);
                }
            }
        }
        return m;
    }

    template <typename Type, int Rows, int Cols>
    inline Matrix<Type, Rows, Cols> identity(const Type& diag_values)
    {
        Matrix<Type, Rows, Cols> m {};
        for (unsigned int row = 0; row < Rows; row++){
            for (unsigned int col = 0; col < Cols; col++){
                if (row == col)
                {
                    m.set(row, col, diag_values);
                }
            }
        }
        return m;
    }

    template <typename Type>
    inline Matrix<Type, 2, 2> create(const Matrix<Type, 2, 1>& v1, const Matrix<Type, 2, 1>& v2) {
        Matrix<Type, 2, 2> m {};
        m.set(0, 0, v1.get(0, 0));
        m.set(1, 0, v1.get(1, 0));
        m.set(0, 1, v2.get(0, 0));
        m.set(1, 1, v2.get(1, 0));
        return m;
    }

    template <typename Type>
    inline Matrix<Type, 2, 2> create(const Matrix<Type, 1, 2>& v1, const Matrix<Type, 1, 2>& v2) {
        Matrix<Type, 2, 2> m {};
        m.set(0, 0, v1.get(0, 0));
        m.set(0, 1, v1.get(0, 1));
        m.set(1, 0, v2.get(0, 0));
        m.set(1, 1, v2.get(0, 1));
        return m;
    }

    template <typename Type>
    inline Matrix<Type, 3, 3> create(const Matrix<Type, 3, 1>& v1, const Matrix<Type, 3, 1>& v2, const Matrix<Type, 3, 1>& v3) {
        Matrix<Type, 3, 3> m {};
        m.set(0, 0, v1.get(0, 0));
        m.set(1, 0, v1.get(1, 0));
        m.set(2, 0, v1.get(2, 0));
        m.set(0, 1, v2.get(0, 0));
        m.set(1, 1, v2.get(1, 0));
        m.set(2, 1, v2.get(2, 0));
        m.set(0, 2, v3.get(0, 0));
        m.set(1, 2, v3.get(1, 0));
        m.set(2, 2, v3.get(2, 0));
        return m;
    }

    template <typename Type>
    inline Matrix<Type, 3, 3> create(const Matrix<Type, 1, 3>& v1, const Matrix<Type, 1, 3>& v2, const Matrix<Type, 1, 3>& v3) {
        Matrix<Type, 3, 3> m {};
        m.set(0, 0, v1.get(0, 0));
        m.set(0, 1, v1.get(0, 1));
        m.set(0, 2, v1.get(0, 2));
        m.set(1, 0, v2.get(0, 0));
        m.set(1, 1, v2.get(0, 1));
        m.set(1, 2, v2.get(0, 2));
        m.set(2, 0, v3.get(0, 0));
        m.set(2, 1, v3.get(0, 1));
        m.set(2, 2, v3.get(0, 2));
        return m;
    }

    template <typename Type>
    inline Matrix<Type, 4, 4> create(const Matrix<Type, 3, 1>& v1, const Matrix<Type, 3, 1>& v2, const Matrix<Type, 3, 1>& v3, const Type& w) {
        Matrix<Type, 4, 4> m {};
        m.set(0, 0, v1.get(0, 0));
        m.set(1, 0, v1.get(1, 0));
        m.set(2, 0, v1.get(2, 0));
        m.set(0, 1, v2.get(0, 0));
        m.set(1, 1, v2.get(1, 0));
        m.set(2, 1, v2.get(2, 0));
        m.set(0, 2, v3.get(0, 0));
        m.set(1, 2, v3.get(1, 0));
        m.set(2, 2, v3.get(2, 0));
        
        m.set(3, 3, w);
        return m;
    }

    template <typename Type>
    inline Matrix<Type, 4, 4> create(const Matrix<Type, 1, 3>& v1, const Matrix<Type, 1, 3>& v2, const Matrix<Type, 1, 3>& v3, const Type& w) {
        Matrix<Type, 4, 4> m {};
        m.set(0, 0, v1.get(0, 0));
        m.set(0, 1, v1.get(0, 1));
        m.set(0, 2, v1.get(0, 2));
        m.set(1, 0, v2.get(0, 0));
        m.set(1, 1, v2.get(0, 1));
        m.set(1, 2, v2.get(0, 2));
        m.set(2, 0, v3.get(0, 0));
        m.set(2, 1, v3.get(0, 1));
        m.set(2, 2, v3.get(0, 2));

        m.set(3, 3, w);
        return m;
    }

    template <typename Type>
    inline Matrix<Type, 4, 4> create(const Matrix<Type, 1, 4>& v1, const Matrix<Type, 1, 4>& v2, const Matrix<Type, 1, 4>& v3, const Matrix<Type, 1, 4>& v4) {
        Matrix<Type, 4, 4> m {};
        m.set(0, 0, v1.get(0, 0));
        m.set(0, 1, v1.get(0, 1));
        m.set(0, 2, v1.get(0, 2));
        m.set(0, 3, v1.get(0, 3));
        m.set(1, 0, v2.get(0, 0));
        m.set(1, 1, v2.get(0, 1));
        m.set(1, 2, v2.get(0, 2));
        m.set(1, 3, v2.get(0, 3));
        m.set(2, 0, v3.get(0, 0));
        m.set(2, 1, v3.get(0, 1));
        m.set(2, 2, v3.get(0, 2));
        m.set(2, 3, v3.get(0, 3));
        m.set(3, 0, v4.get(0, 0));
        m.set(3, 1, v4.get(0, 1));
        m.set(3, 2, v4.get(0, 2));
        m.set(3, 3, v4.get(0, 3));
        return m;
    }

    template <typename Type>
    inline Matrix<Type, 4, 4> create(const Matrix<Type, 4, 1>& v1, const Matrix<Type, 4, 1>& v2, const Matrix<Type, 4, 1>& v3, const Matrix<Type, 4, 1>& v4) {
        return mat::create(v1.transpose(), v2.transpose(), v3.transpose(), v4.transpose());
    }
}

#endif