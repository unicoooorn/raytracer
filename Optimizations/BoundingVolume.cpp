#include "BoundingVolume.h"

BoundingVolume::BoundingVolume(const Scene& scene) : BoundingVolume(scene.objects, 0, scene.objects.size()) {}

bool BoundingVolume::collide(const Ray& r, Boundaries bounds, Collision& collision) const {
    if (!bounding_box.Collide(r, bounds))
        return false;

    bool collision_left = left->collide(r, bounds, collision);
    bool collision_right = right->collide(r, Boundaries(bounds.min, collision_left ? collision.parameter : bounds.max), collision);

    return collision_left || collision_right;
}

BoundingBox BoundingVolume::get_bounding_box() const{
    return bounding_box;
}


bool BoundingVolume::compare(
        const shared_ptr<Opaque>& lhs, const shared_ptr<Opaque>& rhs, int axis
) {
    return lhs->get_bounding_box().GetAxisBound(axis).min < rhs->get_bounding_box().GetAxisBound(axis).min;
}

auto BoundingVolume::compare_by_axis(int axis) {
    return [=](const shared_ptr<Opaque>& lhs, const shared_ptr<Opaque>& rhs) {
        return compare(lhs, rhs, axis);
    };
}

BoundingVolume::BoundingVolume(const std::vector<shared_ptr<Opaque>>& src_objects, size_t start, size_t end) {
    auto objects = src_objects;
    int axis = random_int(0,2);

    size_t object_span = end - start;


    if (object_span == 1) {
        left = right = objects[start];
    } else if (object_span == 2) {
        if (compare(objects[start], objects[start + 1], axis)) {
            left = objects[start];
            right = objects[start+1];
        } else {
            left = objects[start+1];
            right = objects[start];
        }
    } else {
        std::sort(objects.begin() + start, objects.begin() + end, compare_by_axis(axis));

        auto mid = start + object_span/2;
        left = make_shared<BoundingVolume>(objects, start, mid);
        right = make_shared<BoundingVolume>(objects, mid, end);
    }

    bounding_box = BoundingBox(left->get_bounding_box(), right->get_bounding_box());
}
