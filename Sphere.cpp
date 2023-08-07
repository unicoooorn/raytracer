#include "Sphere.h"
#include <cmath>

Sphere::Sphere() = default;

Sphere::Sphere(Vec3 center, double radius) : center(center), radius(radius) {};


bool Sphere::collide(const Ray &ray, double min_param, double max_param, Collision &collision) const {
    Vec3 oc = ray.origin() - center;
    // dot((direction(parameter) - C), (direction(parameter) - C)) = R*R
    // dot((A + parameter*B - C), (A + parameter*B - C)) = R*R
    // parameter*parameter*dot(B, B) + 2*parameter*dot(A-C, A-C) + dot(C, C) - R*R=0
    // parameter^2 * a + 2t*b + c = 0
    // solve quadratic equation
    double a = dot(ray.direction(), ray.direction());
    double b = 2.0 * dot(oc, ray.direction());
    double c = dot(oc, oc) - radius * radius;
    double discriminant = b * b - 4.0 * a * c;
    if (discriminant > 0) {
        double x1 = (-b - sqrt(discriminant)) / (2.0 * a);
        if (x1 < max_param && x1 > min_param) {
            collision.parameter = x1;
            collision.direction = ray.point_at_parameter(collision.parameter);
            collision.normal = (collision.direction - center) / radius;
            return true;
        }

        double x2 = (-b + sqrt(discriminant)) / (2.0 * a);
        if (x2 < max_param && x2 > min_param) {
            collision.parameter = x2;
            collision.direction = ray.point_at_parameter(collision.parameter);
            collision.normal = (collision.direction - center) / radius;
            return true;
        }
    }
    return false;
}
