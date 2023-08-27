#ifndef RAYTRACING_BOUNDINGBOX_H
#define RAYTRACING_BOUNDINGBOX_H

#include "../Utility/Utility.h"
#include "../Utility/Boundaries.h"
#include "../Core/Vec.h"
#include "../Core/Ray.h"

class BoundingBox {
public:
    Boundaries axis_bounds[3];

    BoundingBox();

    BoundingBox(const Boundaries& x_bounds, const Boundaries& y_bounds, const Boundaries& z_bounds);

    BoundingBox(const Point& a, const Point& b);

    [[nodiscard]] bool Collide(const Ray& ray, Boundaries hit_box) const;

    [[nodiscard]] Boundaries GetAxisBound(unsigned int axis) const;

    BoundingBox(const BoundingBox& box0, const BoundingBox& box1);

    BoundingBox pad();
};

#endif //RAYTRACING_BOUNDINGBOX_H
