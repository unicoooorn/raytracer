#ifndef RAYTRACING_MATERIAL_H
#define RAYTRACING_MATERIAL_H

#include "Ray.h"
#include "Opaque.h"

class Material {
public:
    virtual bool diffuse(const Ray& r_in, const Collision& rec, Vec3& attenuation, Ray& scattered) const = 0;
};


#endif //RAYTRACING_MATERIAL_H
