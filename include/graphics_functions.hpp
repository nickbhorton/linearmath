#ifndef GRAPHICS_HEADER
#define GRAPHICS_HEADER

#include "class_forward_declaration.hpp"

// Special Functions
namespace mat {
template <typename Type>
inline Matrix<Type, 4, 4> view(
    const ColVector<Type, 3>& u, 
    const ColVector<Type, 3>& v, 
    const ColVector<Type, 3>& n, 
    const ColVector<Type, 3>& e) {
    Matrix<Type, 4, 4> result {};
    result.set(0, 0, u.get(0));
    result.set(0, 1, u.get(1));
    result.set(0, 2, u.get(2));
    result.set(1, 0, v.get(0));
    result.set(1, 1, v.get(1));
    result.set(1, 2, v.get(2));
    result.set(2, 0, n.get(0));
    result.set(2, 1, n.get(1));
    result.set(2, 2, n.get(2));

    result.set(0, 3, -vec::dot(u, e));
    result.set(1, 3, -vec::dot(v, e));
    result.set(2, 3, -vec::dot(n, e));

    result.set(3, 3, (Type) 1);
    return result;
}

inline Matrix<float, 4, 4> ortho(
    float bot, float top, float left, float right, float near, float far) {
    Matrix<float, 4, 4> result {};
    result.set(0, 0, 2.0f/(right - left));
    result.set(1, 1, 2.0f/(top - bot));
    result.set(2, 2, -2.0f/(far - near));

    result.set(0, 3, -(left + right)/(right - left));
    result.set(1, 3, -(bot + top)/(top - bot));
    result.set(2, 3, -(near + far)/(far - near));

    result.set(3, 3, 1.0f);
    return result;
}

inline Matrix<float, 4, 4> perspective(
    float bot, float top, float left, float right, float near, float far) {
    Matrix<float, 4, 4> result {};
    result.set(0, 0, (near*2.0f)/(right - left));
    result.set(1, 1, (near*2.0f)/(top - bot));

    result.set(1, 2, (top + bot)/(top - bot));
    result.set(0, 2, (right + left)/(right - left));
    result.set(2, 2, -(far + near)/(far - near));

    result.set(2, 3, -2.0f*(near * far)/(far - near));
    result.set(3, 2, -1.0f);
    return result;
}

} // namespace mat

#endif