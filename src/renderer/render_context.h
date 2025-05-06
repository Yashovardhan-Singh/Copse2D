#ifndef RENDER_CONTEXT_H
#define RENDER_CONTEXT_H

#include <stdint.h>
#include <stdlib.h>

#include "render_objects.h"
#include "render_batch.h"
#include "shaders.h"
#include "dshaders.h"

typedef struct RenderContext {
    RenderObjects* renderer;
    RenderBatch batch;
    Shader shader;
} RenderContext;

#endif