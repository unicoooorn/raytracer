#include "Monochrome.h"

Monochrome::Monochrome(Color c) : color(c) {}

Monochrome::Monochrome(double red, double green, double blue) : Monochrome(Color(red,green,blue)) {}

Color Monochrome::value(double u, double v, const Point& p) const {
    return color;
}