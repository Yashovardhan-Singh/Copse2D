#ifndef RENDER_BATCH_H
#define RENDER_BATCH_H

#include <stdlib.h>
#include <stdint.h>

typedef struct RenderBatch {
    float *VBOdata;
    uint32_t *EBOdata;
    size_t VBOcapacity, EBOcapacity;
    size_t VBOcount, EBOcount;
} RenderBatch;

RenderBatch RenderBatchInit();
void RenderBatchDestroy(RenderBatch* rb);

#endif