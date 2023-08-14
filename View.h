#ifndef RAYTRACING_VIEW_H
#define RAYTRACING_VIEW_H

#include "Utility.h"
#include "Color.h"
#include "Opaque.h"
#include <iostream>

class View {
public:
    double screen_ratio = 1.0;
    int screen_width = 100;
    int aa_samples_count = 10;
    Vec aa_horizontal_delta;
    Vec aa_vertical_delta;
    int raytracing_depth = 10;

    // view entrypoint, responsible for image rendering
    void render(const Opaque &world);

private:
    int screen_height;
    Point screen_center;
    Point screen_lower_left_corner;

    void init();

    [[nodiscard]] Color trace(const Ray &r, int depth, const Opaque &world) const;

    [[nodiscard]] Ray get_ray_to(int i, int j) const;

    [[nodiscard]] Vec get_random_close_pixel() const;
};


#endif //RAYTRACING_VIEW_H
