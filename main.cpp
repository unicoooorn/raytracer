#include "Ray.h"
#include "Scene.h"
#include "Sphere.h"
#include "Material.h"
#include "View.h"
#include "Utility.h"
#include "Matte.h"
#include "Transparent.h"
#include "Metal.h"

int main() {
    Scene world;

    auto material_ground = make_shared<Matte>(Color(0.8, 0.8, 0.0));
    auto material_center = make_shared<Matte>(Color(0.1, 0.2, 0.5));
    auto material_left   = make_shared<Transparent>(1.5);
    auto material_right  = make_shared<Metal>(Color(0.8, 0.6, 0.2), 0.0);

    world.add(make_shared<Sphere>(Point(0, -100.5, -1.0), 100.0, material_ground));
    world.add(make_shared<Sphere>(Point(0, 0, -1.0), 0.5, material_center));
    world.add(make_shared<Sphere>(Point(-1.0, 0.0, -1.0), 0.5, material_left));
    world.add(make_shared<Sphere>(Point(-1.0, 0.0, -1.0), -0.4, material_left));
    world.add(make_shared<Sphere>(Point(1.0, 0.0, -1.0), 0.5, material_right));

    View view;

    view.screen_ratio = 16.0 / 9.0;
    view.screen_width  = 400;
    view.aa_samples_count = 100;
    view.raytracing_depth = 50;

    view.render(world);
}