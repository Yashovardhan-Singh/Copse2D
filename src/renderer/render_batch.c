#include "render_batch.h"
#include "vertex.h"

#include <stdlib.h>
#include <string.h>

#define FLOATS_PER_VERTEX 8
#define MAX_VERTEX_PER_ARRAY 2048
#define MAX_FLOATS_IN_ARRAY 16384

#define ELEMENTS_PER_QUAD 6
#define MAX_QUADS_PER_BATCH 512
#define MAX_INDICES_PER_EBO ( MAX_QUADS_PER_BATCH * ELEMENTS_PER_QUAD )

RenderBatch RenderBatchInit() {
    RenderBatch rb = { 0 };
    
    rb.VBOcapacity = MAX_FLOATS_IN_ARRAY;
    rb.VBOdata = malloc(rb.VBOcapacity * sizeof(float));
    rb.VBOcount = 0;
    
    rb.EBOcapacity = MAX_INDICES_PER_EBO;
    rb.EBOdata = malloc(rb.EBOcapacity * sizeof(uint32_t));
    rb.EBOcount = 0;

    return rb;
}

uint8_t RenderBatchCheckCapacity(RenderBatch* rb) {
    return (uint8_t) (
        rb->VBOcount >= rb->VBOcapacity
        || rb->VBOcapacity - rb->VBOcount < 32
    );
}

void RenderBatchAddVertex(RenderBatch* rb, Vertex vertex) {
    uint32_t offset = rb->VBOcount;
    rb->VBOdata[offset + 0] = vertex.x;
    rb->VBOdata[offset + 1] = vertex.y;
    rb->VBOdata[offset + 2] = vertex.u;
    rb->VBOdata[offset + 3] = vertex.v;
    rb->VBOdata[offset + 4] = vertex.r;
    rb->VBOdata[offset + 5] = vertex.g;
    rb->VBOdata[offset + 6] = vertex.b;
    rb->VBOdata[offset + 7] = vertex.a;
    rb->VBOcount += 8;
}

void RenderBatchUpdateQuadIndices(RenderBatch* rb) {
    uint32_t vertexOffset = (rb->VBOcount / 8) - 4; // 4 vertices per quad
    uint32_t offset = rb->EBOcount;
    rb->EBOdata[offset + 0] = vertexOffset + 0;
    rb->EBOdata[offset + 1] = vertexOffset + 1;
    rb->EBOdata[offset + 2] = vertexOffset + 2;
    rb->EBOdata[offset + 3] = vertexOffset + 2;
    rb->EBOdata[offset + 4] = vertexOffset + 3;
    rb->EBOdata[offset + 5] = vertexOffset + 1;
    rb->EBOcount += 6;
}

void RenderBatchReset(RenderBatch *rb) {
    memset(rb->VBOdata, 0, rb->VBOcapacity * sizeof(float));
    rb->VBOcount = 0;

    memset(rb->EBOdata, 0, rb->EBOcapacity * sizeof(float));
    rb->EBOcount = 0;
}

void RenderBatchDestroy(RenderBatch *rb) {
    free(rb->VBOdata);
    free(rb->EBOdata);
}