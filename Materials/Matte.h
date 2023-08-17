#ifndef RAYTRACING_MATTE_H
#define RAYTRACING_MATTE_H

#include "../Core/Ray.h"
#include "../Core/Color.h"
#include "Material.h"
#include "../Textures/Texture.h"

class Matte : public Material {
public:
    explicit Matte(const Color& a);

    explicit Matte(const shared_ptr<Texture>& a);


    bool scatter(const Ray& r_in, const Collision& collision, Color& attenuation, Ray& scattered)
    const override;

private:
    shared_ptr<Texture> reflectance;
};

#endif //RAYTRACING_MATTE_H
