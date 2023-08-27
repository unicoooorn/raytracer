#include "Boundaries.h"

Boundaries::Boundaries() : min(+infinity), max(-infinity) {}

Boundaries::Boundaries(double t_min, double t_max) : min(t_min), max(t_max) {}

[[nodiscard]] bool Boundaries::contains(double x) const {
    return min <= x && x <= max;
}

[[nodiscard]] bool Boundaries::strictly_contains(double x) const {
    return min < x && x < max;
}

[[nodiscard]] double Boundaries::get_closest_num_to(double x) const {
    if (contains(x)) {
        return x;
    }
    return x < min ? min : max;
}

const Boundaries Boundaries::empty   (+infinity, -infinity);
const Boundaries Boundaries::universe(-infinity, +infinity);

double Boundaries::size() const {
    return max - min;
}

Boundaries Boundaries::expand(double delta) const {
    auto padding = delta/2;
    return {min - padding, max + padding};
}

Boundaries::Boundaries(const Boundaries& a, const Boundaries& b)
        : min(std::min(a.min, b.min)), max(std::max(a.max, b.max)) {}