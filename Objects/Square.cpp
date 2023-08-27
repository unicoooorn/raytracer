#include "Square.h"

 bool Square::is_intersecting(double a, double b, Collision& collision) const {
    if ((a < 0) || (1 < a) || (b < 0) || (1 < b))
        return false;

    collision.object_u = a;
    collision.object_v = b;
    return true;
}

// todo везде где есть collision можно заменить контракт на контракт с nullptr, хотя немного грязь
bool Square::collide(const Ray& ray, Boundaries bounds, Collision& collision) const {
    double normalizer = dot_product(normal, ray.direction());

    if (std::abs(normalizer) < std::numeric_limits<double>::epsilon())   // parallel
        return false;

    double parameter = (shift - dot_product(normal, ray.origin())) / normalizer;
    if (!bounds.contains(parameter))
        return false;

    Point intersection = ray.at(parameter);
    Vec collision_vec = intersection - origin;
    double collision_proj_u = dot_product(w, cross_product(collision_vec, v));
    double collision_proj_v = dot_product(w, cross_product(u, collision_vec));

    if (!is_intersecting(collision_proj_u, collision_proj_v, collision))
        return false;

    collision.parameter = parameter;
    collision.point = intersection;
    collision.material = material;
    collision.set_outside_normal(ray, normal);

    return true;
}

[[nodiscard]] BoundingBox Square::get_bounding_box() const { return bounding_box; }

void Square::set_bounding_box() {
    bounding_box = BoundingBox(origin, origin + u + v).pad();
}

Square::Square(const Point& t_origin, const Vec& t_u, const Vec& t_v, shared_ptr<Material> material)
        : origin(t_origin), u(t_u), v(t_v), material(std::move(material))
{
    Vec n = cross_product(u, v);
    w = n / dot_product(n, n);   // w is a common multiplier

    normal = normalize(n);
    shift = dot_product(normal, origin);
    set_bounding_box();
}