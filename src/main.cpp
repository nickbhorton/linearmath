#include <iostream>
#include "../include/matrix.hpp"

int main() {
    vec4i x = vec::create(1, 2, 3, 4);
    vec4i y = vec::create(5, 6, 7, 8);
    vec4i z = vec::create(9, 10, 11, 12);
    vec4i w = vec::create(13, 14, 15, 16);
    mat4i m = mat::create(x, y, z, w);
    std::cout << x << "\n";
}