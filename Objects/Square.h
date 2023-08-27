#ifndef RAYTRACING_SQUARE_H
#define RAYTRACING_SQUARE_H

#include <utility>

#include "Opaque.h"

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


#endif //RAYTRACING_SQUARE_H
