#ifndef RAYTRACING_SCENE_H
#define RAYTRACING_SCENE_H

#include "Opaque.h"

#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;

class Scene : public Opaque {
public:
    std::vector<shared_ptr<Opaque>> objects;

    Scene();

    explicit Scene(shared_ptr<Opaque> object);

    void clear();

    void add(const shared_ptr<Opaque>& object);

    bool collide(const Ray& ray, Boundaries bounds, Collision& collision) const override;

    BoundingBox get_bounding_box() const override;

private:
    BoundingBox bbox;
};

#endif //RAYTRACING_SCENE_H
