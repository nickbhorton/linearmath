#ifndef GRAPHICS_HEADER
#define GRAPHICS_HEADER

#include "class_forward_declaration.hpp"

// Special Functions
namespace mat {
template <typename Type>
inline Matrix<Type, 4, 4> view(
    const ColVector<Type, 3>& camera_right, 
    const ColVector<Type, 3>& camera_up, 
    const ColVector<Type, 3>& camera_behind, 
    const ColVector<Type, 3>& camera_location) {
    Matrix<Type, 4, 4> result {};
    result.set(0, 0, camera_right.get(0));
    result.set(0, 1, camera_right.get(1));
    result.set(0, 2, camera_right.get(2));
    result.set(1, 0, camera_up.get(0));
    result.set(1, 1, camera_up.get(1));
    result.set(1, 2, camera_up.get(2));
    result.set(2, 0, camera_behind.get(0));
    result.set(2, 1, camera_behind.get(1));
    result.set(2, 2, camera_behind.get(2));

    result.set(0, 3, -vec::dot(camera_right, camera_location));
    result.set(1, 3, -vec::dot(camera_up, camera_location));
    result.set(2, 3, -vec::dot(camera_behind, camera_location));

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

    result.set(0, 2, (right + left)/(right - left));
    result.set(1, 2, (top + bot)/(top - bot));
    result.set(2, 2, -(far + near)/(far - near));

    result.set(2, 3, (-2.0f * near * far)/(far - near));
    result.set(3, 2, -1.0f);
    return result;
}

} // namespace mat

#endif