#ifndef RAYTRACING_SQUARE_H
#define RAYTRACING_SQUARE_H

#include <utility>

#include "Opaque.h"
#include "../Objects/Scene.h"

class Square: public Opaque {
public:
    Square(const Point& t_origin, const Vec& t_u, const Vec& t_v, shared_ptr<Material> material);

    void set_bounding_box();

    [[nodiscard]] BoundingBox get_bounding_box() const override;

    bool collide(const Ray& ray, Boundaries bounds, Collision& collision) const override;

private:
    // square is a parallelogram built on u and v originating from origin
    Point origin;
    Vec u, v;
    shared_ptr<Material> material;
    BoundingBox bounding_box;
    Vec normal;
    Vec w;
    double shift;

    virtual bool is_intersecting(double a, double b, Collision& collision) const;
};

inline shared_ptr<Scene> get_box(const Point& a, const Point& b, shared_ptr<Material> material)
{
    auto faces = make_shared<Scene>();

    Point lower_left = Point(std::min(a.x(), b.x()), std::min(a.y(), b.y()), std::min(a.z(), b.z()));
    Point upper_right = Point(std::max(a.x(), b.x()), std::max(a.y(), b.y()), std::max(a.z(), b.z()));

    Vec height = Vec(upper_right.x() - lower_left.x(), 0, 0);
    Vec width = Vec(0, upper_right.y() - lower_left.y(), 0);
    Vec depth = Vec(0, 0, upper_right.z() - lower_left.z());

    faces->add(make_shared<Square>(Point(lower_left.x(), lower_left.y(), upper_right.z()), height, width, material)); // front
    faces->add(make_shared<Square>(Point(upper_right.x(), lower_left.y(), upper_right.z()), -depth, width, material)); // right
    faces->add(make_shared<Square>(Point(upper_right.x(), lower_left.y(), lower_left.z()), -height, width, material)); // back
    faces->add(make_shared<Square>(Point(lower_left.x(), lower_left.y(), lower_left.z()), depth, width, material)); // left
    faces->add(make_shared<Square>(Point(lower_left.x(), upper_right.y(), upper_right.z()), height, -depth, material)); // top
    faces->add(make_shared<Square>(Point(lower_left.x(), lower_left.y(), lower_left.z()), height, depth, material)); // bottom

    return faces;
}


#endif //RAYTRACING_SQUARE_H
