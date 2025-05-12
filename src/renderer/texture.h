#ifndef TEXTURE_H
#define TEXTURE_H

#include <stdint.h>

typedef struct Texture {
    uint32_t Id;
    uint32_t width, height;
    uint32_t channels;
} Texture;

Texture TextureCreate(const char* filename);
void TextureDestroy(Texture texture);

#endif //TEXTURE_H
