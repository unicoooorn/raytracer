#include "Vec.h"
#include <cmath>


Vec::Vec() : e{0, 0, 0}{};

Vec::Vec(double e0, double e1, double e2) : e{e0, e1, e2} {}

double Vec::x() const { return e[0]; }

double Vec::y() const { return e[1]; }

double Vec::z() const { return e[2]; }

Vec Vec::operator-() const {
    return {-e[0], -e[1], -e[2]};
}

double Vec::operator[](int i) const {
    return e[i];
}

double &Vec::operator[](int i) {
    return e[i];
}

Vec &Vec::operator+=(const Vec &other) {
    e[0] += other.e[0];
    e[1] += other.e[1];
    e[2] += other.e[2];
    return *this;
}

Vec &Vec::operator*=(double multiplier) {
    e[0] *= multiplier;
    e[1] *= multiplier;
    e[2] *= multiplier;
    return *this;
}

Vec &Vec::operator/=(double divisor) {
    return *this *= 1/divisor;
}

double Vec::length() const {
    return sqrt(length_squared());
}

double Vec::length_squared() const {
    return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
}

Vec Vec::random_vec() {
    return {random_double(), random_double(), random_double()};
}

Vec Vec::random_vec(double min, double max) {
    return {random_double(min, max), random_double(min, max), random_double(min, max)};
}

bool Vec::near_zero() const {
    auto s = 1e-8;
    return (fabs(e[0]) < s) && (fabs(e[1]) < s) && (fabs(e[2]) < s);
}

using Point = Vec;

std::ostream &operator<<(std::ostream &out, const Vec &v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

Vec operator+(const Vec &u, const Vec &v) {
    return {u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]};
}

Vec operator-(const Vec &u, const Vec &v) {
    return {u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]};
}

Vec operator*(const Vec &u, const Vec &v){
    return {u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]};
}

Vec operator*(double multiplier, const Vec &v) {
    return {multiplier * v.e[0], multiplier * v.e[1], multiplier * v.e[2]};
}

Vec operator*(const Vec &v, double multiplier) {
    return multiplier * v;
}

Vec operator/(const Vec &v, const double divisor) {
    return {v[0] / divisor, v[1] / divisor, v[2] / divisor};
}

double dot_product(const Vec &u, const Vec &v) {
    return u[0] * v[0] + u[1] * v[1] + u[2] * v[2];
}

Vec cross_product(const Vec &u, const Vec &v) {
    return {u.e[1] * v.e[2] - u.e[2] * v.e[1],
            u.e[2] * v.e[0] - u.e[0] * v.e[2],
            u.e[0] * v.e[1] - u.e[1] * v.e[0]};
}

Vec normalize(Vec vec) {
    return vec / vec.length();
}

Vec get_random_point_in_unit_sphere() {
    while (true) {
        auto p = Vec::random_vec(-1, 1);
        if (p.length_squared() < 1)
            return p;
    }
}

Vec get_random_unit_vector() {
    return normalize(get_random_point_in_unit_sphere());
}

Vec get_random_unit_vector_in_hemisphere(const Vec &normal) {
    Vec unit_vector = get_random_unit_vector();
    if (dot_product(unit_vector, normal) > 0.0)
        return unit_vector;
    else
        return -unit_vector;
}

Vec reflect(const Vec &v, const Vec &n) {
    return v - 2 * dot_product(v, n) * n;
}

Vec refract(const Vec &uv, const Vec &n, double indexes_ratio) {
    auto cos_theta = fmin(dot_product(-uv, n), 1.0);
    Vec r_out_perp = indexes_ratio * (uv + cos_theta * n);
    Vec r_out_parallel = -sqrt(fabs(1.0 - r_out_perp.length_squared())) * n;
    return r_out_perp + r_out_parallel;
}

Vec random_in_unit_disk() {
    while (true) {
        auto p = Vec(random_double(-1,1), random_double(-1,1), 0);
        if (p.length_squared() < 1)
            return p;
    }
}
