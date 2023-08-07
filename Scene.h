#ifndef RAYTRACING_SCENE_H
#define RAYTRACING_SCENE_H

#include "Opaque.h"

class Scene: public Opaque{
    int size;
    Opaque **objects;
public:
    Scene();
    Scene(Opaque **l , int n);
    bool collide(const Ray& ray, double min_param, double max_param, Collision& collision) const override;
};


#endif //RAYTRACING_SCENE_H
