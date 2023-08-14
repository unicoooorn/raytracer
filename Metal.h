#ifndef RAYTRACING_METAL_H
#define RAYTRACING_METAL_H

#include "Material.h"
#include "Color.h"
#include "Ray.h"

class Metal : public Material {
public:
    Metal(const Color& a, double f);
    bool scatter(const Ray& r_in, const Collision& collision, Color& attenuation, Ray& scattered)
    const override;

private:
    Color albedo;
    double fuzz;
};


#endif //RAYTRACING_METAL_H
