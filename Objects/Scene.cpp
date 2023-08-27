#include "Scene.h"
#include "Opaque.h"

#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;

std::vector<shared_ptr<Opaque>> objects;

Scene::Scene() = default;

Scene::Scene(shared_ptr<Opaque> object) { add(object); }

void Scene::clear() { objects.clear(); }

void Scene::add(const shared_ptr<Opaque> &object) {
    objects.push_back(object);
    bbox = BoundingBox(bbox, object->get_bounding_box());
}

bool Scene::collide(const Ray &ray, Boundaries bounds, Collision &collision) const {
    Collision t_collision;
    bool is_collided = false;
    auto closest_collision_parameter = bounds.max;

    for (const auto &object: objects) {
        if (object->collide(ray, Boundaries(bounds.min, closest_collision_parameter), t_collision)) {
            is_collided = true;
            closest_collision_parameter = t_collision.parameter;
            collision = t_collision;
        }
    }

    return is_collided;
}

BoundingBox Scene::get_bounding_box() const { return bbox; }
