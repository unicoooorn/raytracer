#include "Sphere.h"
#include <cmath>
#include <utility>

Sphere::Sphere(Point t_center, double t_radius, shared_ptr<Material> t_material) : center(t_center), radius(t_radius), mat(std::move(t_material)) {}

bool Sphere::collide(const Ray& ray, Boundaries bounds, Collision& collision) const {
    Vec oc = ray.origin() - center;
    auto a = ray.direction().length_squared();
    auto half_b = dot_product(oc, ray.direction());
    auto c = oc.length_squared() - radius*radius;

    auto discriminant = half_b*half_b - a*c;
    if (discriminant < 0) return false;
    auto sqrtd = sqrt(discriminant);

    auto root = (-half_b - sqrtd) / a;
    if (!bounds.strictly_contains(root)) {
        root = (-half_b + sqrtd) / a;
        if (!bounds.strictly_contains(root))
            return false;
    }

    collision.parameter = root;
    collision.point = ray.at(collision.parameter);
    Vec outward_normal = (collision.point - center) / radius;
    collision.set_outside_normal(ray, outward_normal);
    collision.material = mat;

    return true;
}