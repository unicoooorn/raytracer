#ifndef RAYTRACING_MATERIAL_H
#define RAYTRACING_MATERIAL_H

#include "../Utility/Utility.h"
#include "../Core/Ray.h"
#include "../Core/Color.h"
#include "../Objects/Opaque.h"

class Material {
public:
    virtual ~Material() = default;

    virtual bool scatter(
            const Ray& r_in, const Collision& rec, Color& attenuation, Ray& scattered) const = 0;
};

#endif //RAYTRACING_MATERIAL_H
