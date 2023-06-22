# 3D Curves Hierarchy

This project is a C++ library that provides support for a hierarchy of 3D curves. It includes classes for circles, ellipses, and 3D helixes, allowing you to work with different types of curves in a 3D space. The library offers functionality to calculate 3D points and first derivatives along the curves based on a parameter.

## Table of Contents

- [Requirements](#requirements)
- [Building the Project](#building-the-project)

# Requirements

To build and run this project, you need the following:

- C++ compiler with C++11 support
- CMake (3.9 or higher)
- OpenMP library

## Building the Project

Follow the steps below to build the project using CMake:

1. Clone the repository:

   ```shell
   git clone https://github.com/IstariTM/3d-curves-hierarchy.git

2. Create a build directory and navigate into it:
   ```shell
   cd 3d-curves-hierarchy
   mkdir build
   cd build
3. Generate the build files using CMake:
   ```shell
   cmake ..
4. Build the project:
   ```shell
   cmake --build .
   
This will compile the source files and generate the executable.
   
