#include "Color.h"

double linear_to_gamma(double linear_component)
{
    return sqrt(linear_component);
}

void write_pixel_ppm(std::ostream &out, Color color, unsigned int sample_count) {
    auto scale = 1.0 / sample_count;
    color *= scale;

    auto r = color.x();
    auto g = color.y();
    auto b = color.z();

    r = linear_to_gamma(r);
    g = linear_to_gamma(g);
    b = linear_to_gamma(b);

    static const Boundaries intensity(0.000, 0.999);
    out << static_cast<int>(256 * intensity.get_closest_num_to(r)) << ' '
        << static_cast<int>(256 * intensity.get_closest_num_to(g)) << ' '
        << static_cast<int>(256 * intensity.get_closest_num_to(b)) << '\n';
}
