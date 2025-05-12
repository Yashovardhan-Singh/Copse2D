#ifndef RENDER_BATCH_H
#define RENDER_BATCH_H

#include <stdlib.h>
#include <stdint.h>
#include "vertex.h"

typedef struct RenderBatch {
    float *VBOdata;
    uint32_t *EBOdata;
    size_t VBOcapacity, EBOcapacity;
    size_t VBOcount, EBOcount;
} RenderBatch;

RenderBatch RenderBatchInit();
uint8_t RenderBatchCheckCapacity(RenderBatch* rb);
void RenderBatchAddVertex(RenderBatch* rb, Vertex vertex);
void RenderBatchUpdateQuadIndices(RenderBatch* rb);
void RenderBatchReset(RenderBatch* rb);
void RenderBatchDestroy(RenderBatch* rb);

#endif