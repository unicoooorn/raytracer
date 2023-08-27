#include "Sphere.h"
#include <cmath>
#include <utility>

Sphere::Sphere(Point t_center, double t_radius, shared_ptr<Material> t_material) : center(t_center), radius(t_radius), mat(std::move(t_material)) {
    auto radius_vec = Vec(radius, radius, radius);
    bbox = BoundingBox(t_center - radius_vec, t_center + radius_vec);
}

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
    get_texture_coords(outward_normal, collision.object_u, collision.object_v);
    collision.material = mat;

    return true;
}

void Sphere::get_texture_coords(const Point& p, double& u, double& v) {
    // converting space coord to spherical coords
    double theta = acos(-p.y());
    double phi = atan2(-p.z(), p.x()) + pi;

    // converting space coord to plain texture coords
    u = phi / (2*pi);
    v = theta / pi;
}

BoundingBox Sphere::get_bounding_box() const {
    return bbox;
}
