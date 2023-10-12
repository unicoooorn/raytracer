#ifndef RAYTRACING_LIGHT_H
#define RAYTRACING_LIGHT_H

#include <utility>

#include "../Textures/Texture.h"
#include "../Core/Collision.h"
#include "../Core/Ray.h"
#include "Material.h"
#include "../Textures/Monochrome.h"

class Light : public Material {
public:
    explicit Light(shared_ptr<Texture> a) : color(std::move(a)) {}
    explicit Light(Color c) : color(make_shared<Monochrome>(c)) {}

    bool scatter(const Ray& r_in, const Collision& rec, Color& attenuation, Ray& scattered)
    const override {
        return false;
    }

    [[nodiscard]] Color emitted(double u, double v, const Point& p) const override {
        return color->value(u, v, p);
    }

private:
    shared_ptr<Texture> color;
};


#endif //RAYTRACING_LIGHT_H
