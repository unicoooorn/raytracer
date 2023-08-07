#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H

#include "Vec3.h"


class Ray {
    Vec3 A;
    Vec3 B;
public:
    Ray();
    Ray(const Vec3& a, const Vec3& b);
    Vec3 origin() const;
    Vec3 direction() const;
    Vec3 point_at_parameter(double t) const;
};


#endif //RAYTRACER_RAY_H
