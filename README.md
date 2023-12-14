<div align="center">
  
# Nicks Linear Math Library (NLML)
![cpp][cpp-badge]

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
### View
The view matrix shift verticies into the cameras corrdinates. 
```math
  \begin{bmatrix}
  cr_{x} && cr_{y} && cr_{z} && -\vec{cp} \cdot \vec{cr} \\
  cu_{x} && cu_{y} && cu_{z} && -\vec{cp} \cdot \vec{cu} \\
  cb_{x} && cb_{y} && cb_{z} && -\vec{cp} \cdot \vec{cb} \\
  0 && 0 && 0 && 1
  \end{bmatrix}
```
| Parameter name | Matrix name | Description | Type |
| :-- | -- | -- | -: |
| *Camera right* | _cr_ | Unit vector defining right from the camera view direction. | `ColVector<T, 3, 3>` |
| *Camera up* | _cu_ | Unit vector defining up from the camera view direction. | `ColVector<T, 3, 3>` |
| *Camera behind* | _cb_ | Negitive camera view direction. | `ColVector<T, 3, 3>` |
| *Camera position* | _cp_ | Position of camera in scene. | `ColVector<T, 3, 3>` |




[cpp-badge]: https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white
