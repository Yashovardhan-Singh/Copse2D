// Public API

#ifndef RENDERER_H
#define RENDERER_H

#include <stdint.h>
#include "color.h"
#include "render_context.h"
#include "texture.h"

typedef struct RenderableObject {
    // Texture data
    Texture tex;
    float u1, v1;
    float u2, v2;

    // Position data
    float x1, y1; // origin
    float x2, y2; // x2 = x1 + w, y2 = y1 + h
    // Color data
    Color color;
} RObject;

void DrawObject(RenderContext* context, RObject* object);

#endif