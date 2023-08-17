cmake_minimum_required(VERSION 3.26)

PROJECT(RayTracing)

set (CMAKE_CXX_STANDARD 20)

ADD_EXECUTABLE(${PROJECT_NAME} main.cpp Core/Vec.h Core/Vec.cpp Core/Color.h
        Core/Color.cpp
        Core/View.h
        Materials/Material.h
        Utility/Boundaries.cpp
        Core/Collision.cpp
        Materials/Matte.cpp
        Materials/Metal.h
        Materials/Metal.cpp
        Materials/Transparent.h
        Materials/Transparent.cpp
        Core/Ray.cpp
        Objects/Scene.cpp
        Objects/Sphere.cpp
        Core/View.cpp
        Textures/Texture.h
        Textures/Checkered.h
        Textures/Checkered.cpp
        Textures/Monochrome.h
        Textures/Monochrome.cpp)