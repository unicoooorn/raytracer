#include "Ray.h"

Ray::Ray() = default;

Ray::Ray(const Point& origin, const Vec& direction) : orig(origin), dir(direction) {}

Point Ray::origin() const  { return orig; }
Vec Ray::direction() const { return dir; }

Point Ray::at(double t) const {
    return orig + t*dir;
}