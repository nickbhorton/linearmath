<div align="center">
  
# Nicks Linear Math Library (NLML)
https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white
<img src="{https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white}" />

Linear math is an intuitive header only library for matrix and vector math needed for graphics programming. It provides 1 primary class, the matrix class, and two derivitive classes, column vector, and row vector. 

[Getting started](#getting-started) •
[Installation](#installation) •
[Graphics Specific Functions](#graphic-specific-functions) •

</div>

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

## Graphics Specific Functions
<details>
  <summary>View</summary>
</details>
<details>
  <summary>Orthographic</summary>
</details>
<details>
  <summary>Perspective</summary>
</details>
