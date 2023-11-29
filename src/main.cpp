#include <iostream>
#include "../include/matrix.hpp"

int main() {
    vec3i x = vec::create(1, 2, 3);
    vec3i y = vec::create(4, 5, 6);
    vec3i z = vec::create(7, 8, 9);
    mat4i m = mat::create(x, y, z, 1);
    std::cout << "x:\n";
    std::cout << x << "\n";
    std::cout << "y:\n";
    std::cout << y << "\n";
    std::cout << "z:\n";
    std::cout << z << "\n";
    std::cout << "m:\n";
    std::cout << m << "\n";
}