#ifndef TEXTURE_H
#define TEXTURE_H

#include <stdint.h>

typedef struct Texture {
    uint32_t Id;
    uint32_t width, height;
    uint32_t channels;
} Texture;

Texture TextureCreate(const char* filename);    // Binds the texture created
void TextureBind(Texture tex);
void TextureDestroy(Texture tex);

#endif //TEXTURE_H
