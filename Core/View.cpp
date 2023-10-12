#include "View.h"
#include "../Materials/Material.h"

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

    double fov_in_radians = degrees_to_radians(vertical_fov);
    double viewport_height_unit_dist = 2 * tan(fov_in_radians / 2);
    double viewport_height = 2 * viewport_height_unit_dist * focus_dist;
    double viewport_width = viewport_height * (static_cast<double>(screen_width) / screen_height);

    basis_w = normalize(point_of_view - looking_at_point);   // parallel to the gaze
    basis_u = normalize(cross_product(vec_up, basis_w));    // pointing left
    basis_v = cross_product(basis_w, basis_u);   // pointing up

    Vec viewport_horizontal_right = viewport_width * basis_u;
    Vec viewport_vertical_up = viewport_height * -basis_v;

    horizontal_delta_right = viewport_horizontal_right / screen_width;
    vertical_delta_up = viewport_vertical_up / screen_height;

    Vec viewport_upper_left = point_of_view - (focus_dist * basis_w) - viewport_horizontal_right/2 - viewport_vertical_up/2;
    viewport_upper_left_corner = viewport_upper_left + 0.5 * (horizontal_delta_right + vertical_delta_up);

    double lens_radius = focus_dist * tan(degrees_to_radians(defocus_angle / 2));
    lens_u = basis_u * lens_radius;
    lens_v = basis_v * lens_radius;
}

Color View::trace(const Ray &r, int depth, const Opaque &world) const {
    if (depth <= 0)
        return {0, 0, 0};

    Collision collision;

    if (!world.collide(r, Boundaries(0.001, infinity), collision))
        return background;

    Ray scattered;
    Color attenuation;
    Color color_from_emission = collision.material->emitted(collision.object_u, collision.object_v, collision.point);

    if (!collision.material->scatter(r, collision, attenuation, scattered))
        return color_from_emission;

    Color  color_from_scatter = attenuation * trace(scattered, depth-1, world);

    return color_from_emission + color_from_scatter;
}

Ray View::get_ray_to(int i, int j) const {
    auto pixel_center = viewport_upper_left_corner + (i * horizontal_delta_right) + (j * vertical_delta_up);
    auto pixel_sample = pixel_center + get_random_close_pixel();

    auto ray_origin = (defocus_angle <= 0) ? point_of_view : get_lens_sample();
    auto ray_direction = pixel_sample - ray_origin;

    return {ray_origin, ray_direction};
}

Point View::get_lens_sample() const {
    Vec p = random_in_unit_disk();
    return point_of_view + (p[0] * lens_u) + (p[1] * lens_v);
}

Vec View::get_random_close_pixel() const {
    auto px = -0.5 + random_double();
    auto py = -0.5 + random_double();
    return (px * horizontal_delta_right) + (py * vertical_delta_up);
}