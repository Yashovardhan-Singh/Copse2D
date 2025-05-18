#include "texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "../../vendor/stb_image/stb_image.h"
#include "../../vendor/glad/gl.h"

Texture TextureCreate(const char* filename) {
    Texture tex = { 0 };

    stbi_set_flip_vertically_on_load(1);
    uint8_t* data = stbi_load(filename, (int*) &tex.width, (int*) &tex.height, (int*) &tex.channels, 0);

    int32_t format = GL_RGBA;
    if (tex.channels == 3) format = GL_RGB;
    else if (tex.channels == 4) format = GL_RGBA;

    glGenTextures(1, &tex.Id);
    glBindTexture(GL_TEXTURE_2D, tex.Id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); // or GL_LINEAR
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, format, tex.width, tex.height, 0, format, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(data);
    return tex;
}

void TextureBind(Texture tex) {
    glBindTexture(GL_TEXTURE_2D, tex.Id);
}

void TextureDestroy(Texture tex) {
    glDeleteTextures(1, &tex.Id);
}