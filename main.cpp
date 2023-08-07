#include <iostream>
#include "Vec3.h"
#include "Ray.h"
#include "Opaque.h"
#include "Sphere.h"
#include "Matte.h"
#include "Scene.h"
#include "View.h"

const int SCREEN_HEIGHT = 100;
const int SCREEN_WIDTH = 200;
const int ANTIALISING_CYCLES = 200;
const double BEAM_CONST = 255.99;

Vec3 trace(const Ray& r, Opaque *world) {
    Collision rec;
    if (world->collide(r, 0.0, MAXFLOAT, rec)) {
        Vec3 target = rec.direction + rec.normal + get_random_direction();
        return 0.5 * trace(Ray(rec.direction, target - rec.direction), world);
    } else {
        Vec3 unit_direction = unit_vector(r.direction());
        double t = 0.5 * (unit_direction.y() + 1.0);
        return (1.0 - t) * Vec3(1.0, 1.0, 1.0) + t * Vec3(0.5, 0.7, 1.0);
    }
}

Vec3 calculate_pixel_color(int i, int j, Opaque *opaque_objects, View *view) {
    Vec3 color(0, 0, 0);
    // antialiasing
    for (int s = 0; s < ANTIALISING_CYCLES; s++) {
        float u = float(i + drand48())/ float(SCREEN_WIDTH);
        float v = float(j + drand48()) / float(SCREEN_HEIGHT);
        Ray r = view->get_ray(u, v);
        color += trace(r, opaque_objects);
    }
    color /= double(ANTIALISING_CYCLES);

    color = Vec3(sqrt(color.r()), sqrt(color.g()), sqrt(color.b()));    // slight re-shading

    int red = int(BEAM_CONST * color.r());
    int green = int(BEAM_CONST * color.g());
    int blue = int(BEAM_CONST * color.b());

    std::cout << red << " " << green << " " << blue << "\n";
}

int main() {
    std::cout << "P3\n" << SCREEN_WIDTH << " " << SCREEN_HEIGHT << "\n255\n";

    Opaque *objects[2] = {
            new Sphere(Vec3(0, 0, -1), 0.5),
            new Sphere(Vec3(0, -100.5, -1), 100),
    };
    Opaque *world = new Scene(objects, 2);
    View *view = new View();

    for (int j = SCREEN_HEIGHT - 1; j >= 0; j--) {
        for (int i = 0; i < SCREEN_WIDTH; i++) {
            calculate_pixel_color(i, j, world, view);
        }
    }
}