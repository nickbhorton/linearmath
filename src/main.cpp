#include <iostream>
#include "../include/matrix.hpp"

int main() {
    vec3i v = vec::create(1, 1, 1);
    auto result = v.transpose() * v;
    std::cout << result << "\n";
}