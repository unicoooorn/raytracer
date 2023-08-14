#ifndef RAYTRACING_MATTE_H
#define RAYTRACING_MATTE_H

#include "Ray.h"
#include "Color.h"
#include "Material.h"

class Matte : public Material {
public:
    explicit Matte(const Color& a);

    bool scatter(const Ray& r_in, const Collision& collision, Color& attenuation, Ray& scattered)
    const override;

private:
    Color reflectance;
};

#endif //RAYTRACING_MATTE_H
