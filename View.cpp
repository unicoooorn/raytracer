#include "View.h"
#include "Material.h"

void View::render(const Opaque &world) {
    init();

    std::cout << "P3\n" << screen_width << ' ' << screen_height << "\n255\n";

    for (int j = 0; j < screen_height; ++j) {
        std::clog << "\rLines remaining: " << (screen_height - j) << ' ' << std::flush;
        for (int i = 0; i < screen_width; ++i) {
            Color color(0, 0, 0);
            for (int sample = 0; sample < aa_samples_count; ++sample) {
                Ray r = get_ray_to(i, j);
                color += trace(r, raytracing_depth, world);
            }
            write_pixel_ppm(std::cout, color, aa_samples_count);
        }
    }

    std::clog << "\rDone.                 \n";
}

void View::init() {
    screen_height = static_cast<int>(screen_width / screen_ratio);
    screen_height = (screen_height < 1) ? 1 : screen_height;

    screen_center = Point(0, 0, 0);

    auto focal_length = 1.0;
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (static_cast<double>(screen_width) / screen_height);

    auto viewport_u = Vec(viewport_width, 0, 0);
    auto viewport_v = Vec(0, -viewport_height, 0);

    aa_horizontal_delta = viewport_u / screen_width;
    aa_vertical_delta = viewport_v / screen_height;

    auto viewport_upper_left =
            screen_center - Vec(0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;
    screen_lower_left_corner = viewport_upper_left + 0.5 * (aa_horizontal_delta + aa_vertical_delta);
}

Color View::trace(const Ray &r, int depth, const Opaque &world) const {
    if (depth <= 0)
        return {0, 0, 0};

    Collision collision;

    if (world.collide(r, Boundaries(0.001, infinity), collision)) {
        Ray scattered;
        Color attenuation;
        if (collision.material->scatter(r, collision, attenuation, scattered))
            return attenuation * trace(scattered, depth-1, world);
        return Color(0,0,0);
    }

    Vec unit_direction = normalize(r.direction());
    auto a = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - a) * Color(1.0, 1.0, 1.0) + a * Color(0.5, 0.7, 1.0);
}

Ray View::get_ray_to(int i, int j) const {
    auto pixel_center = screen_lower_left_corner + (i * aa_horizontal_delta) + (j * aa_vertical_delta);
    auto pixel_sample = pixel_center + get_random_close_pixel();

    auto ray_origin = screen_center;
    auto ray_direction = pixel_sample - ray_origin;

    return Ray(ray_origin, ray_direction);
}

Vec View::get_random_close_pixel() const {
    auto px = -0.5 + random_double();
    auto py = -0.5 + random_double();
    return (px * aa_horizontal_delta) + (py * aa_vertical_delta);
}