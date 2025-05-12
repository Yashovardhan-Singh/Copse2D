#ifndef RENDER_OBJECTS_H
#define RENDER_OBJECTS_H

#include <stdint.h>
#include "render_batch.h"

typedef struct RenderObjects {
    uint32_t VAO;
    uint32_t VBO;
    uint32_t EBO;
} RenderObjects;

RenderObjects RenderObjectsInit();
void RenderObjectsFlushVBO(RenderObjects* ro, RenderBatch* rb);
void RenderObjectsFlushEBO(RenderObjects* ro, RenderBatch* rb);
void RenderObjectsDestroy(RenderObjects* renderer);

#endif