#include "Metal.h"

Metal::Metal(const Color &a, double f) : albedo(a), fuzz(f < 1 ? f : 1) {}

bool Metal::scatter(const Ray &r_in, const Collision &collision, Color &attenuation, Ray &scattered) const {
    Vec reflected = reflect(normalize(r_in.direction()), collision.normal);
    scattered = Ray(collision.point, reflected + fuzz * get_random_unit_vector());
    attenuation = albedo;
    return dot_product(scattered.direction(), collision.normal) > 0;
}