#include "Scene.h"

Scene::Scene() = default;

Scene::Scene(Opaque **l, int n) {
    objects = l;
    size = n;
};

bool Scene::collide(const Ray& ray, double min_param, double max_param, Collision &collision) const {
    Collision t_collision;
    bool is_colliding = false;
    double param = max_param;   // param to relax
    for (int i = 0; i < size; i++) {
        if (objects[i]->collide(ray, min_param, param, t_collision)) {
            is_colliding = true;
            param = t_collision.parameter;
            collision = t_collision;
        }
    }
    return is_colliding;
}
