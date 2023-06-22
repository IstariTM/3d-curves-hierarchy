cmake_minimum_required (VERSION 3.9)

project ("3d_curves_hierarchy")

find_package(OpenMP REQUIRED)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(3d_curves SHARED "3d_curves.cpp" "3d_curves.h" )

add_executable (3d_curves_hierarchy "3d_curves.h" "main.cpp")

set_target_properties(3d_curves PROPERTIES PUBLIC_HEADER 3d_curves.h)

target_link_libraries(3d_curves_hierarchy PUBLIC
    3d_curves
)

target_link_libraries(3d_curves_hierarchy PUBLIC 
    OpenMP::OpenMP_CXX
)
