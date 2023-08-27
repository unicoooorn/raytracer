#ifndef RAYTRACING_OPAQUE_H
#define RAYTRACING_OPAQUE_H

#include "../Core/Ray.h"
#include "../Utility/Utility.h"
#include "../Utility/Boundaries.h"
#include "../Core/Collision.h"
#include "../Optimizations/BoundingBox.h"

class Opaque {
public:
    virtual ~Opaque() = default;

    virtual bool collide(const Ray& r, Boundaries bounds, Collision& collision) const = 0;

    virtual BoundingBox get_bounding_box() const = 0;
};

#endif //RAYTRACING_OPAQUE_H
