#include "texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "../../vendor/stb_image/stb_image.h"
#include "../../vendor/glad/gl.h"

Texture TextureCreate(const char* filename) {
    Texture tex = { 0 };
    uint8_t* data = stbi_load(filename, (int*) &tex.width, (int*) &tex.height, (int*) &tex.channels, 0);
    glGenTextures(1, &tex.Id);
    glBindTexture(GL_TEXTURE_2D, tex.Id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, tex.width, tex.height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(data);
    return tex;
}

void TextureDestroy(Texture tex) {
    glDeleteTextures(1, &tex.Id);
}