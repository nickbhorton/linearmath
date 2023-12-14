<div align="center">
  
# Nicks Linear Math Library (NLML)
Linear math is an intuitive header only library for matrix and vector math needed for graphics programming.

</div>

[Getting started](#getting-started) •

## Getting started

```cpp
vec3f my_vector = vec::create(2.4, 3.6, -1.2);
mat3f my_matrix = identity<float, 3, 3>();
std::cout << my_matrix * my_vector << "\n";
```

## Installation
C++14 is the current standard for this library, and the goal is to have the headers be compiler and enviroment independant. To use the headers: clone the repository and include the matrix.hpp file where needed. 
```sh
git clone "https://github.com/nickbhorton/linearmath.git"
```

```cpp
// my_code.cpp
#include "matrix.hpp"
...
```
