#include "View.h"

View::View() {
    lower_left_bound = Vec3(-2.0, -1.0, -1.0);
    horizontal_fov = Vec3(4.0, 0.0, 0.0);
    vertical_fov = Vec3(0.0, 2.0, 0.0);
    position = Vec3(0.0, 0.0, 0.0);
}

Ray View::get_ray(double u, double v) const {
    return {position, lower_left_bound + u * horizontal_fov + v * vertical_fov - position};
}
