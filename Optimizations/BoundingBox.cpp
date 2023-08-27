#include "BoundingBox.h"

Boundaries axis_bounds[3];

BoundingBox::BoundingBox() = default;

BoundingBox::BoundingBox(const Boundaries& x_bounds, const Boundaries& y_bounds, const Boundaries& z_bounds)
        : axis_bounds{x_bounds, y_bounds, z_bounds} { }

BoundingBox::BoundingBox(const Point& a, const Point& b) {
    axis_bounds[0] = Boundaries(std::min(a[0],b[0]), std::max(a[0],b[0]));
    axis_bounds[1] = Boundaries(std::min(a[1],b[1]), std::max(a[1],b[1]));
    axis_bounds[2] = Boundaries(std::min(a[2],b[2]), std::max(a[2],b[2]));
}

[[nodiscard]] bool BoundingBox::Collide(const Ray& ray, Boundaries hit_box) const {
    for (int axis = 0; axis < 3; axis++) {
        auto bounds = axis_bounds[axis];

        // dealing with parallel rays
        double t0 = std::min((bounds.min - ray.origin()[axis]) / ray.direction()[axis],
                             (bounds.max - ray.origin()[axis]) / ray.direction()[axis]);
        double t1 = std::max((bounds.min - ray.origin()[axis]) / ray.direction()[axis],
                             (bounds.max - ray.origin()[axis]) / ray.direction()[axis]);

        hit_box.min = std::max(t0, hit_box.min);
        hit_box.max = std::min(t1, hit_box.max);
        if (hit_box.max <= hit_box.min)
            return false;
    }
    return true;
}

[[nodiscard]] Boundaries BoundingBox::GetAxisBound(unsigned int axis) const {
    return axis_bounds[axis];
}

BoundingBox::BoundingBox(const BoundingBox& box0, const BoundingBox& box1) {
    axis_bounds[0] = Boundaries(box0.axis_bounds[0], box1.axis_bounds[0]);
    axis_bounds[1] = Boundaries(box0.axis_bounds[1], box1.axis_bounds[1]);
    axis_bounds[2] = Boundaries(box0.axis_bounds[2], box1.axis_bounds[2]);
}

BoundingBox BoundingBox::pad() {
    // todo to the values or const
    double delta = 0.001;

    Boundaries new_boundaries[3];

    for (int i = 0; i < 3; i++) {
        new_boundaries[i] = (axis_bounds[i].size() >= delta) ? axis_bounds[i] : axis_bounds[i].expand(delta);
    }

    // todo replace with copy constructor
    return {new_boundaries[0], new_boundaries[1], new_boundaries[2]};
}
