#ifndef RAYTRACING_VIEW_H
#define RAYTRACING_VIEW_H

#include "../Utility/Utility.h"
#include "Color.h"
#include "../Objects/Opaque.h"
#include <iostream>

class View {
public:
    double screen_ratio = 1.0;
    int screen_width = 100;
    int aa_samples_count = 10;
    Vec horizontal_delta_right;
    Vec vertical_delta_up;
    int raytracing_depth = 10;

    Point point_of_view = Point(0, 0, -1);
    Point looking_at_point = Point(0, 0, 0);
    Vec vec_up = Vec(0, 1, 0);

    double vertical_fov = 90;

    // view entrypoint, responsible for image rendering
    void render(const Opaque &world);

    double defocus_angle = 0;  // Variation angle of rays through each pixel
    double focus_dist = 10;

private:
    int screen_height;
    Point viewport_upper_left_corner;
    Vec   basis_u, basis_v, basis_w;    // w is parallel to gaze, u is to the right, v is up vector
    Vec   lens_u;  // Defocus disk horizontal radius
    Vec   lens_v;  // Defocus disk vertical radius

    void init();

    [[nodiscard]] Color trace(const Ray &r, int depth, const Opaque &world) const;

    [[nodiscard]] Ray get_ray_to(int i, int j) const;

    [[nodiscard]] Vec get_random_close_pixel() const;

    Point get_lens_sample() const;
};


#endif //RAYTRACING_VIEW_H
