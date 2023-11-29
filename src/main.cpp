#include <iostream>
#include "../include/matrix.hpp"

int main() {
    vec3i x = vec::create(1, 2, 3);
    vec3i y = vec::create(4, 5, 6);
    vec3i z = vec::create(7, 8, 9);
    mat3i m = mat::create(x, y, z).transpose();
    mat2i m_0_0 = m.minor(0, 0);
    std::cout << m << "\n";
    std::cout << m_0_0 << "\n";
}