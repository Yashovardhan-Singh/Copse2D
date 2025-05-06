#ifndef ROBJECT_H
#define ROBJECT_H

#include <stdint.h>
#include "vertex.h"
#include "color.h"

typedef struct RenderableObject {
    uint32_t TextureID;
    Vertex origin;
    Color color;
} RObject;

#endif