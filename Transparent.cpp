#include "Transparent.h"

Transparent::Transparent(double index_of_refraction) : refraction_index(index_of_refraction) {}

bool Transparent::scatter(const Ray &r_in, const Collision &collision, Color &attenuation, Ray &scattered)
const {
    attenuation = Color(1.0, 1.0, 1.0);
    double refraction_ratio = collision.is_outside ? (1.0 / refraction_index) : refraction_index;

    Vec unit_direction = normalize(r_in.direction());
    double cos_theta = fmin(dot_product(-unit_direction, collision.normal), 1.0);
    double sin_theta = sqrt(1.0 - cos_theta * cos_theta);

    bool is_reflecting = refraction_ratio * sin_theta > 1.0;
    Vec direction;

    if (is_reflecting || reflectance(cos_theta, refraction_ratio) > random_double())
        direction = reflect(unit_direction, collision.normal);
    else
        direction = refract(unit_direction, collision.normal, refraction_ratio);

    scattered = Ray(collision.point, direction);
    return true;
}

// Schlick's approximation for reflectance
double Transparent::reflectance(double cosine, double ref_idx) {
    auto r0 = (1 - ref_idx) / (1 + ref_idx);
    r0 = r0 * r0;
    return r0 + (1 - r0) * pow((1 - cosine), 5);
}