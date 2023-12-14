<div align="center">
  
# Nicks Linear Math Library (NLML)
![cpp][cpp-badge]

Linear math is an intuitive header only library for matrix and vector math needed for graphics programming. It provides 1 primary class, the matrix class, and two derivative classes, column vector, and row vector. 

[Getting started](#getting-started) •
[Installation](#installation) •
[Graphics Specific Functions](#graphic-specific-functions) •

</div>

## Getting started

```cpp title="my_cpp.hpp" linenums="1"
#include "Matrix.hpp"
int main() {
  vec3f my_vector = vec::create(2.4, 3.6, -1.2);
  mat3f my_matrix = identity<float, 3, 3>();
  std::cout << (my_matrix * my_vector).transpose() << "\n";
}
```
```
2.4    3.6   -1.2
```

## Usage
C++14 is the current standard for this library, and the goal is to have the headers be compiler and environment independent. To use the headers: clone the repository and include the matrix.hpp file where needed. 
```sh
git clone "https://github.com/nickbhorton/linearmath.git"
```
### Building and running the testing suit
This shell script should work on most linux environments with common development libraries `git`, `cmake`, and `make`. Script was tested in a ArchLinux environment.
```sh title="build_tests.sh"
#!/bin/sh
git clone "https://github.com/nickbhorton/linearmath.git"
cd linearmath
git submodule init
git submodule update
mkdir -v build
cd build
cmake .. -G "Unix Makefiles"
make
ctest
```

## Common Graphics Specific Functions
### Object Transformation
#### Model (`mat::model`)
TOIMPL
#### View (`mat::view`)
The view matrix transforms the scene from scene coordinates into the cameras coordinates. After a model transformation an object is defined relative scene coordinates. The camera has some orientation with respect to scene coordinates, ie the camera is located somewhere and has a viewing direction (this direction defines a new axis system). The matrix below is defines the view transformation.
```math title
  \begin{bmatrix}
  cr_{x} && cr_{y} && cr_{z} && -\vec{cp} \cdot \vec{cr} \\
  cu_{x} && cu_{y} && cu_{z} && -\vec{cp} \cdot \vec{cu} \\
  cb_{x} && cb_{y} && cb_{z} && -\vec{cp} \cdot \vec{cb} \\
  0 && 0 && 0 && 1
  \end{bmatrix}
```
| Parameter name | Matrix name | Description | Type |
| :-- | -- | -- | -: |
| *Camera right* | _cr_ | Unit vector defining right from the camera view direction. | `#!cpp ColVector<T,3>` |
| *Camera up* | _cu_ | Unit vector defining up from the camera view direction. | `#!cpp ColVector<T,3>` |
| *Camera behind* | _cb_ | Negitive camera view direction. | `#!cpp ColVector<T,3>` |
| *Camera position* | _cp_ | Position of camera in scene. | `#!cpp ColVector<T,3>` |

### Perspective Transformations
#### Orthographic
TODO
#### Perspective
TODO


[cpp-badge]: https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white
