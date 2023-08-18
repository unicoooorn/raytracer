#include "ImageTexture.h"

ImageTexture::ImageTexture(const char* filename) : Image(filename) {}

Color ImageTexture::value(double u, double v, const Point& p) const {
    if (Image.height() <= 0) return {0,1,1};

    u = Boundaries(0,1).get_closest_num_to(u);
    v = 1.0 - Boundaries(0,1).get_closest_num_to(v);

    auto i = static_cast<int>(u * Image.width());
    auto j = static_cast<int>(v * Image.height());
    auto pixel = Image.pixel_data(i,j);

    auto Color_scale = 1.0 / 255.0;
    return {Color_scale*pixel[0], Color_scale*pixel[1], Color_scale*pixel[2]};
}
