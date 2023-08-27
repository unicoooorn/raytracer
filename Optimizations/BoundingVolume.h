#ifndef RAYTRACING_BOUNDINGVOLUME_H
#define RAYTRACING_BOUNDINGVOLUME_H

#include "../Objects/Scene.h"
#include "../Objects/Opaque.h"
#include "../Core/Ray.h"
#include "../Utility/Boundaries.h"
#include "../Core/Collision.h"
#include <vector>

class BoundingVolume : public Opaque {
public:
    explicit BoundingVolume(const Scene& scene);

    BoundingVolume(const std::vector<shared_ptr<Opaque>>& src_objects, size_t start, size_t end);

    bool collide(const Ray& r, Boundaries bounds, Collision& collision) const override;

    [[nodiscard]] BoundingBox get_bounding_box() const override;
private:
    static bool compare(
            const shared_ptr<Opaque>& lhs, const shared_ptr<Opaque>& rhs, int axis
    );

    static auto compare_by_axis(int axis);

    shared_ptr<Opaque> left;
    shared_ptr<Opaque> right;
    BoundingBox bounding_box;
};

#endif //RAYTRACING_BOUNDINGVOLUME_H
