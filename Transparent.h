#ifndef RAYTRACING_TRANSPARENT_H
#define RAYTRACING_TRANSPARENT_H

#include "Material.h"
#include "Ray.h"
#include "Collision.h"

class Transparent : public Material {
public:
    explicit Transparent(double index_of_refraction);

    bool scatter(const Ray& r_in, const Collision& collision, Color& attenuation, Ray& scattered) const override;

private:
    double refraction_index;

    static double reflectance(double cosine, double ref_idx);
};

#endif //RAYTRACING_TRANSPARENT_H
