#ifndef RAYTRACING_MONOCHROME_H
#define RAYTRACING_MONOCHROME_H

#include "../Core/Color.h"
#include "../Textures/Texture.h"

class Monochrome : public Texture {
public:
    explicit Monochrome(Color c);

    Monochrome(double red, double green, double blue);

    [[nodiscard]] Color value(double u, double v, const Point& p) const override;

private:
    Color color;
};



#endif //RAYTRACING_MONOCHROME_H
