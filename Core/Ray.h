#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H

#include "Vec.h"

class Ray {
public:
    Ray();

    Ray(const Point& origin, const Vec& direction);

    [[nodiscard]] Point origin() const;
    [[nodiscard]] Vec direction() const;

    [[nodiscard]] Point at(double t) const;

private:
    Point orig;
    Vec dir;
};

#endif //RAYTRACER_RAY_H
