#include "Matte.h"
#include <cstdlib>

Matte::Matte(const Color &a) : reflectance(a) {}

bool Matte::scatter(const Ray &r_in, const Collision &collision, Color &attenuation, Ray &scattered)
const {
    auto new_dir = collision.normal + get_random_unit_vector();

    if (new_dir.near_zero())
        new_dir = collision.normal;

    scattered = Ray(collision.point, new_dir);
    attenuation = reflectance;
    return true;
}
