#ifndef RAYTRACING_SPHERE_H
#define RAYTRACING_SPHERE_H

#include "Opaque.h"

class Sphere : public Opaque {
public:
    Sphere(Point t_center, double t_radius, shared_ptr<Material> t_material);

    bool collide(const Ray& ray, Boundaries bounds, Collision& collision) const override;

private:
    Point center;
    double radius;
    shared_ptr<Material> mat;
};


#endif //RAYTRACING_SPHERE_H
