#ifndef RAYTRACING_TEXTURE_H
#define RAYTRACING_TEXTURE_H

#include "../Core/Color.h"

class Texture {
public:
    virtual ~Texture() = default;

    virtual Color value(double u, double v, const Point& p) const = 0;
};

#endif //RAYTRACING_TEXTURE_H
