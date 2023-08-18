#ifndef RAYTRACING_IMAGETEXTURE_H
#define RAYTRACING_IMAGETEXTURE_H


#include "../Utility/Utility.h"
#include "../Core/Color.h"
#include "../Utility/Image.h"
#include "Texture.h"

class ImageTexture : public Texture {
public:
    explicit ImageTexture(const char* filename) : Image(filename);

    [[nodiscard]] Color value(double u, double v, const Point& p) const override;

private:
    Image Image;
};


#endif //RAYTRACING_IMAGETEXTURE_H
