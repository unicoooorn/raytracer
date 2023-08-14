#ifndef RAYTRACING_OPAQUE_H
#define RAYTRACING_OPAQUE_H

#include "Ray.h"
#include "Utility.h"
#include "Boundaries.h"
#include "Collision.h"

class Opaque {
public:
    virtual ~Opaque() = default;

    virtual bool collide(const Ray& r, Boundaries bounds, Collision& collision) const = 0;
};

#endif //RAYTRACING_OPAQUE_H
