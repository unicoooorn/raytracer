#include "Matte.h"
#include <cstdlib>

Vec3 get_random_direction() {
    Vec3 direction;
    do {
        direction = 2.0 * Vec3(drand48(), drand48(), drand48()) - Vec3(1, 1, 1);
    } while (dot(direction, direction) >= 1.0);
    return direction;
}

Matte::Matte(const Vec3 &a) : reflectance(a) {};

bool Matte::diffuse(const Ray &ray, const Collision &collision, Vec3 &attenuation, Ray &diffused) const {
    Vec3 direction = collision.direction + collision.normal + get_random_direction();
    diffused = Ray(collision.direction, direction - collision.direction);
    attenuation = reflectance;
    return (dot(diffused.direction(), collision.normal) > 0);
}
