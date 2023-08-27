#ifndef RAYTRACING_BOUNDARIES_H
#define RAYTRACING_BOUNDARIES_H

#include <numeric>

const double infinity = std::numeric_limits<double>::infinity();

class Boundaries {
public:
    double min, max;

    Boundaries();

    Boundaries(double t_min, double t_max);

    [[nodiscard]] bool contains(double x) const;

    [[nodiscard]] bool strictly_contains(double x) const;

    [[nodiscard]] double get_closest_num_to(double x) const;

    [[nodiscard]] double size() const;

    [[nodiscard]] Boundaries expand(double delta) const;

    Boundaries(const Boundaries& a, const Boundaries& b);

    static const Boundaries empty, universe;
};

#endif //RAYTRACING_BOUNDARIES_H
