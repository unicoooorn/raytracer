#include "Checkered.h"

#include <utility>
#include "Monochrome.h"


Checkered::Checkered(double t_scale, shared_ptr<Texture> t_even, shared_ptr<Texture> t_odd)
        : inv_scale(1.0 / t_scale), even(std::move(t_even)), odd(std::move(t_odd)) {}

Checkered::Checkered(double t_scale, Color c1, Color c2)
        : inv_scale(1.0 / t_scale),
          even(make_shared<Monochrome>(c1)),
          odd(make_shared<Monochrome>(c2))
{}

Color Checkered::value(double u, double v, const Point& p) const {
    auto x = static_cast<int>(std::floor(inv_scale * p.x()));
    auto y = static_cast<int>(std::floor(inv_scale * p.y()));
    auto z = static_cast<int>(std::floor(inv_scale * p.z()));

    bool isEven = (x + y + z) % 2 == 0;

    return isEven ? even->value(u, v, p) : odd->value(u, v, p);
}