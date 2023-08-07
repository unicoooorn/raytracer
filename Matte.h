#ifndef RAYTRACING_MATTE_H
#define RAYTRACING_MATTE_H

#include "Material.h"

Vec3 get_random_direction();

class Matte : public Material {
    Vec3 reflectance;
public:
    explicit Matte(const Vec3 & a);
    bool diffuse(const Ray& ray, const Collision& collision, Vec3& attenuation, Ray& diffused) const override;
};


#endif //RAYTRACING_MATTE_H
