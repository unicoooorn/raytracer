#ifndef RAYTRACING_VIEW_H
#define RAYTRACING_VIEW_H


#include "Ray.h"

class View {
    Vec3 position;
    Vec3 lower_left_bound;
    Vec3 horizontal_fov;
    Vec3 vertical_fov;
public:
    View();
    Ray get_ray(double u, double v) const;
};


#endif //RAYTRACING_VIEW_H
