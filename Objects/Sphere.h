#ifndef RAYTRACING_SPHERE_H
#define RAYTRACING_SPHERE_H

#include "Opaque.h"

class Sphere : public Opaque {
public:
    Sphere(Point t_center, double t_radius, shared_ptr<Material> t_material);

    bool collide(const Ray& ray, Boundaries bounds, Collision& collision) const override;

    [[nodiscard]] BoundingBox get_bounding_box() const override;

private:
    Point center;
    double radius;
    shared_ptr<Material> mat;
    BoundingBox bbox;

    static void get_texture_coords(const Point& p, double& u, double& v);
};


#endif //RAYTRACING_SPHERE_H
