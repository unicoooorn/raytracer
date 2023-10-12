#include "Core/Ray.h"
#include "Objects/Scene.h"
#include "Objects/Sphere.h"
#include "Materials/Material.h"
#include "Core/View.h"
#include "Utility/Utility.h"
#include "Materials/Matte.h"
#include "Materials/Transparent.h"
#include "Materials/Metal.h"
#include "Textures/Checkered.h"
#include "Textures/Texture.h"
#include <chrono>
#include "Textures/ImageTexture.h"
#include "Optimizations/BoundingVolume.h"
#include "Objects/Square.h"
#include "Materials/Light.h"


void sphere_scene() {
    Scene world;

    auto ground_material = make_shared<Matte>(Color(0.5, 0.5, 0.5));
    world.add(make_shared<Sphere>(Point(0, -1000, 0), 1000, ground_material));

    auto material1 = make_shared<Matte>(Color(0.4, 0.2, 0.1));
    world.add(make_shared<Sphere>(Point(0, 1, 0), 1.0, material1));

#ifdef kdtree
    world = Scene(make_shared<BoundingVolume>(world));
#endif

    View view;

    view.screen_ratio = 16.0 / 9.0;
    view.screen_width = 400;
    view.aa_samples_count = 200;
    view.raytracing_depth = 15;
    view.background = Color(0.70, 0.80, 1.00);


    view.vertical_fov = 20;
    view.point_of_view = Point(7, 2, 3);
    view.looking_at_point = Point(0, 0, 0);
    view.vec_up = Point(0, 1, 0);

    view.defocus_angle = 0.6;
    view.focus_dist = 10.0;

    view.render(world);
}

void cornell_box() {
    Scene world;

    auto red = make_shared<Matte>(Color(.65, .05, .05));
    auto white = make_shared<Matte>(Color(.73, .73, .73));
    auto green = make_shared<Matte>(Color(.12, .45, .15));
    auto light = make_shared<Light>(Color(8, 8, 8));

    world.add(make_shared<Square>(Point(555, 0, 0), Vec(0, 555, 0), Vec(0, 0, 555), green));
    world.add(make_shared<Square>(Point(0, 0, 0), Vec(0, 555, 0), Vec(0, 0, 555), red));
    world.add(make_shared<Square>(Point(111, 554, 111), Vec(333, 0, 0), Vec(0, 0, 333), light));
    world.add(make_shared<Square>(Point(0, 0, 0), Vec(555, 0, 0), Vec(0, 0, 555), white));
    world.add(make_shared<Square>(Point(555, 555, 555), Vec(-555, 0, 0), Vec(0, 0, -555), white));
    world.add(make_shared<Square>(Point(0, 0, 555), Vec(555, 0, 0), Vec(0, 555, 0), white));

    world.add(get_box(Point(130, 0, 65), Point(295, 165, 230), white));
    world.add(get_box(Point(265, 0, 295), Point(430, 330, 460), white));

    View view;

    view.screen_ratio = 1.0;
    view.screen_width = 300;
    view.aa_samples_count = 200;
    view.raytracing_depth = 10;
    view.background = Color(0.2, 0.2, 0.2);

    view.vertical_fov = 40;
    view.point_of_view = Point(278, 278, -400);
    view.looking_at_point = Point(278, 278, 0);
    view.vec_up = Vec(0, 1, 0);

    view.defocus_angle = 0;

    view.render(world);
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    cornell_box();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = duration_cast<std::chrono::milliseconds>(stop - start);

    std::clog << "Taken "
              << duration.count() << " milliseconds" << std::flush;

}