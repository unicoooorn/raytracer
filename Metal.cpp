#include "Metal.h"

Vec3 reflect(const Vec3& vec, const Vec3 &normal) {
    return vec - 2 * dot(vec, normal) * normal;
}