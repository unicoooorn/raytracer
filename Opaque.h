#ifndef RAYTRACING_OPAQUE_H
#define RAYTRACING_OPAQUE_H

#include "Ray.h"

class Material;

struct Collision {
public:
    double parameter{};
    Vec3 direction;
    Vec3 normal;
    Material *material{};
};

class Opaque {
public:
    virtual bool collide(const Ray& r, double min_param, double max_param, Collision &collision) const = 0;
};

#endif //RAYTRACING_OPAQUE_H
