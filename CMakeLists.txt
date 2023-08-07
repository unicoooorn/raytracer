cmake_minimum_required(VERSION 3.26)

PROJECT(RayTracing)

set (CMAKE_CXX_STANDARD 20)

ADD_EXECUTABLE(${PROJECT_NAME} main.cpp Vec3.h Vec3.cpp Ray.h Ray.cpp
        Sphere.cpp
        Scene.cpp
        View.h
        View.cpp
        Material.h
        Matte.h
        Matte.cpp
        Metal.h
        Metal.cpp)