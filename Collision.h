

#ifndef RAYTRACING_COLLISION_H
#define RAYTRACING_COLLISION_H

#include "Vec.h"
#include "Ray.h"

class Material;

class Collision {
public:
    Point point;
    Vec normal;
    bool is_outside;
    shared_ptr<Material> material;
    double parameter;

    void set_outside_normal(const Ray& r, const Vec& unit_outward_normal);
};


#endif //RAYTRACING_COLLISION_H
