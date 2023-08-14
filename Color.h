#ifndef RAYTRACING_COLOR_H
#define RAYTRACING_COLOR_H

#include <iostream>
#include "Vec.h"
#include "Boundaries.h"

using Color = Vec;

double linear_to_gamma(double linear_component);

void write_pixel_ppm(std::ostream &out, Color color, unsigned int aa_sample_count);

#endif //RAYTRACING_COLOR_H
