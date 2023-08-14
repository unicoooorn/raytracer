#ifndef RAYTRACER_VEC3_H
#define RAYTRACER_VEC3_H
#pragma once

#include <cstdlib>
#include <cmath>
#include <iostream>
#include "Utility.h"

using std::sqrt;

class Vec {
public:
    double e[3]{};

    Vec();
    Vec(double e0, double e1, double e2);

    [[nodiscard]] double x() const;
    [[nodiscard]] double y() const;
    [[nodiscard]] double z() const;

    Vec operator-() const;
    double operator[](int i) const;
    double& operator[](int i);

    Vec& operator+=(const Vec &v);

    Vec& operator*=(double t);

    Vec& operator/=(double t);

    [[nodiscard]] double length() const;

    [[nodiscard]] double length_squared() const;

    static Vec random_vec();

    static Vec random_vec(double min, double max);

    [[nodiscard]] bool near_zero() const;
};

using Point = Vec;

std::ostream& operator<<(std::ostream &out, const Vec &v);

Vec operator+(const Vec &lhs, const Vec &rhs);

Vec operator-(const Vec &lhs, const Vec &rhs);

Vec operator*(const Vec &lhs, const Vec &rhs);

Vec operator*(double multiplier, const Vec &vec);

Vec operator*(const Vec &v, double multiplier);

Vec operator/(const Vec &v1, const double divisor);

double dot_product(const Vec &u, const Vec &v);

Vec cross_product(const Vec &u, const Vec &v);

Vec normalize(Vec vec);

Vec get_random_point_in_unit_sphere();

Vec get_random_unit_vector();

Vec get_random_unit_vector_in_hemisphere(const Vec& normal);

Vec reflect(const Vec& v, const Vec& n) ;

Vec refract(const Vec& uv, const Vec& n, double indexes_ratio);

#endif //RAYTRACER_VEC3_H
