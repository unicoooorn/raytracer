cmake_minimum_required(VERSION 3.26)

PROJECT(RayTracing)

set (CMAKE_CXX_STANDARD 20)

ADD_EXECUTABLE(${PROJECT_NAME} main.cpp Vec.h Vec.cpp Color.h
        Color.cpp
        View.h
        Material.h
        Boundaries.cpp
        Collision.cpp
        Matte.cpp
        Metal.h
        Metal.cpp
        Transparent.h
        Transparent.cpp
        Ray.cpp
        Scene.cpp
        Sphere.cpp
        View.cpp)