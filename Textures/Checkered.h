#ifndef RAYTRACING_CHECKERED_H
#define RAYTRACING_CHECKERED_H

#include "Texture.h"

class Checkered : public Texture {
public:
    Checkered(double t_scale, shared_ptr<Texture> t_even, shared_ptr<Texture> t_odd);

    Checkered(double t_scale, Color c1, Color c2);

    Color value(double u, double v, const Point& p) const override;

private:
    double inv_scale;
    shared_ptr<Texture> even;
    shared_ptr<Texture> odd;
};

#endif //RAYTRACING_CHECKERED_H
