#ifndef RAYTRACING_METAL_H
#define RAYTRACING_METAL_H


#include "Vec3.h"
#include "Material.h"

Vec3 reflect(const Vec3& vec, const Vec3 &normal);

class Metal : public Material {
    Vec3 albedo;
};


#endif //RAYTRACING_METAL_H
