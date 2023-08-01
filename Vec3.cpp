#include "Vec3.h"
#include <cmath>

Vec3::Vec3(double e0, double e1, double e2) {
    e[0] = e0;
    e[1] = e1;
    e[2] = e2;
}

double Vec3::x() const { return e[0]; }

double Vec3::y() const { return e[1]; }

double Vec3::z() const { return e[2]; }

double Vec3::r() const { return e[0]; }

double Vec3::g() const { return e[1]; }

double Vec3::b() const { return e[2]; }

const Vec3 &Vec3::operator+() const { return *this; }

Vec3 Vec3::operator-() const { return Vec3(-e[0], -e[1], -e[2]); }

double Vec3::operator[](int i) const { return e[i]; }

double &Vec3::operator[](int i) { return e[i]; }

double Vec3::length() const { return sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]); }

double Vec3::squared_length() const { return e[0] * e[0] + e[1] * e[1] + e[2] * e[2]; }

Vec3& Vec3::operator+=(const Vec3 &v2) {
    e[0] += v2.e[0];
    e[1] += v2.e[1];
    e[2] += v2.e[2];
    return *this;
}

Vec3& Vec3::operator-=(const Vec3 &v2) {
    e[0] -= v2.e[0];
    e[1] -= v2.e[1];
    e[2] -= v2.e[2];
    return *this;
}

Vec3& Vec3::operator*=(const Vec3 &v2) {
    e[0] *= v2.e[0];
    e[1] *= v2.e[1];
    e[2] *= v2.e[2];
    return *this;
}

Vec3& Vec3::operator/=(const Vec3 &v2) {
    e[0] /= v2.e[0];
    e[1] /= v2.e[1];
    e[2] /= v2.e[2];
    return *this;
}

Vec3& Vec3::operator*=(const double t) {
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;
}

Vec3& Vec3::operator/=(const double t) {
    e[0] /= t;
    e[1] /= t;
    e[2] /= t;
    return *this;
}


void Vec3::make_unit_vector() {
    *this /= this->length();
}

Vec3::Vec3() = default;

Vec3 operator+(const Vec3 &v1, const Vec3 &v2) {
    return {v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]};
}

Vec3 operator-(const Vec3 &v1, const Vec3 &v2) {
    return {v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]};
}

Vec3 operator*(const Vec3 &v1, const Vec3 &v2) {
    return {v1.e[0] * v2.e[0], v1.e[1] * v2.e[1], v1.e[2] * v2.e[2]};
}

Vec3 operator/(const Vec3 &v1, const Vec3 &v2) {
    return {v1.e[0] / v2.e[0], v1.e[1] / v2.e[1], v1.e[2] / v2.e[2]};
}

Vec3 operator*(const Vec3 &v1, const double t) {
    return {v1.e[0] * t, v1.e[1] * t, v1.e[2] * t};
}

Vec3 operator*(const double t, const Vec3 &v1) {
    return {v1.e[0] * t, v1.e[1] * t, v1.e[2] * t};
}


Vec3 operator/(const Vec3 &v1, const double t) {
    return {v1.e[0] / t, v1.e[1] / t, v1.e[2] / t};
}

double dot(const Vec3 &v1, const Vec3 &v2) {
    return v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1] + v1.e[2] * v2.e[2];
}

Vec3 cross(const Vec3 &v1, const Vec3 &v2) {
    return {(v1.e[1] * v2.e[2] - v1.e[2] * v2.e[1]),
                (-(v1.e[0] * v2.e[2] - v1.e[2] * v2.e[0])),
                (v1.e[0] * v2.e[1] - v1.e[1] * v2.e[0])};
}

Vec3 unit_vector(Vec3 v) {
    return v / v.length();
}