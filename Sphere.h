#ifndef RAYTRACING_SPHERE_H
#define RAYTRACING_SPHERE_H

#include "Opaque.h"


class Sphere: public Opaque {
private:
    Vec3 center;
    double radius{};
public:
    Sphere();
    Sphere(Vec3 center, double r);
    bool collide(const Ray& ray, double min_param, double max_param, Collision& collision) const override;
};


#endif //RAYTRACING_SPHERE_H
