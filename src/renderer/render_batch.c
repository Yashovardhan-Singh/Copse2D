#include "render_batch.h"
#include "vertex.h"

#define FLOATS_PER_VERTEX 8
#define MAX_FLOATS_IN_ARRAY 16384
#define MAX_VERTICES_PER_VBO ( MAX_FLOATS_IN_ARRAY / FLOATS_PER_VERTEX )
#define MAX_QUADS_PER_BATCH ( MAX_VERTICES_PER_VBO / 4 )

#define ELEMENTS_PER_QUAD 6
#define MAX_INDICES_PER_EBO ( MAX_QUADS_PER_BATCH * ELEMENTS_PER_QUAD )

RenderBatch RenderBatchInit() {
    RenderBatch rb = { 0 };
    
    rb.VBOcapacity = MAX_FLOATS_IN_ARRAY;
    rb.VBOdata = malloc(rb.VBOcapacity * sizeof(float));
    rb.VBOcount = 0;
    
    rb.EBOcapacity = 6 * MAX_QUADS_PER_BATCH;
    rb.EBOdata = malloc(rb.EBOcapacity * sizeof(uint32_t));
    rb.EBOcount = 0;

    return rb;
}

void RenderBatchDestroy(RenderBatch *rb) {
    free(rb->VBOdata);
    free(rb->EBOdata);
}