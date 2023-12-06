cmake_minimum_required(VERSION 3.7...3.27)

if (${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(LinearMath 
    VERSION 0.1 
    DESCRIPTION "C++ classes for commonly used mathematical objects in graphics programming"
    LANGUAGES C CXX) 

add_library(linearmath_headers INTERFACE)

option(PACKAGE_TESTS "Build the tests" ON)
if(PACKAGE_TESTS)
    enable_testing()
    include(GoogleTest)
    add_subdirectory(tests)
endif()

add_subdirectory(src)