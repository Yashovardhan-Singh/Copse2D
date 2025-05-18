// Public API

#ifndef RENDERER_H
#define RENDERER_H

#include <stdint.h>
#include "color.h"
#include "render_context.h"
#include "texture.h"

typedef struct RenderableObject {
    // Texture data
    float u, v;
    float tw, th;

    // Dimension data
    float w, h;

    // Transform Data
    float x, y;
    float scaleX, scaleY;
    float rotation; // radians

    // Color data
    Color color;
} RObject;

void RendererStartFrame(Color color);
void RendererDrawObject(RenderContext* context, RObject* object);
void RendererStopFrame(RenderContext* context);

#endif