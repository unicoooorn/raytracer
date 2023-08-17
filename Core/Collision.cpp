#include "Collision.h"

void Collision::set_outside_normal(const Ray& r, const Vec& unit_outward_normal) {
    is_outside = dot_product(r.direction(), unit_outward_normal) < 0;
    normal = is_outside ? unit_outward_normal : -unit_outward_normal;
}