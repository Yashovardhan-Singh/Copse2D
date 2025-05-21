#ifndef RENDER_CONTEXT_H
#define RENDER_CONTEXT_H

#include "render_objects.h"
#include "render_batch.h"
#include "shaders.h"
#include "dshaders.h"
#include "camera.h"

typedef struct RenderContext {
    RenderObjects renderer;
    RenderBatch batch;
    Shader shader;
    Camera2D camera;
} RenderContext;

RenderContext* RenderContextInit();
void RenderContextDestroy(RenderContext* context);

#endif