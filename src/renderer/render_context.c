#include "render_context.h"

#include <stdlib.h>

RenderContext* RenderContextInit() {
    RenderContext* rc = malloc(sizeof(RenderContext));
    rc->batch = RenderBatchInit();
    rc->renderer = RenderObjectsInit();
    rc->shader = ShaderCreateFromStrings(defaultFragShader, defaultVertShader);
    return rc;
}

void RenderContextDestroy(RenderContext* rc) {
    RenderBatchDestroy(&(rc->batch));
    RenderObjectsDestroy(&(rc->renderer));
    ShaderDestory(rc->shader);
    free(rc);
}