#include "renderer.h"
#include "vertex.h"
#include "../../vendor/glad/gl.h"

void DrawObject(RenderContext* context, RObject* obj) {
    Vertex a = (Vertex) {
        .x = obj->x1, .y = obj->y2,
        .u = obj->u1, .v = obj->v2,
        .r = obj->color.r, .g = obj->color.g, .b = obj->color.b, .a = obj->color.a
    };
    Vertex b = (Vertex) {
        .x = obj->x2, .y = obj->y2,
        .u = obj->u2, .v = obj->v2,
        .r = obj->color.r, .g = obj->color.g, .b = obj->color.b, .a = obj->color.a
    };
    Vertex c = (Vertex) {
        .x = obj->x1, .y = obj->y1,
        .u = obj->u1, .v = obj->v1,
        .r = obj->color.r, .g = obj->color.g, .b = obj->color.b, .a = obj->color.a
    };
    Vertex d = (Vertex) {
        .x = obj->x2, .y = obj->y1,
        .u = obj->u2, .v = obj->v1,
        .r = obj->color.r, .g = obj->color.g, .b = obj->color.b, .a = obj->color.a
    };

    RenderBatchAddVertex(&context->batch, a);
    RenderBatchAddVertex(&context->batch, b);
    RenderBatchAddVertex(&context->batch, c);
    RenderBatchAddVertex(&context->batch, d);
    RenderBatchUpdateQuadIndices(&context->batch);

    RenderObjectsFlushVBO(&context->renderer, &context->batch);
    RenderObjectsFlushEBO(&context->renderer, &context->batch);

    glUseProgram(context->shader);
    glBindVertexArray(context->renderer.VAO);
    glDrawElements(GL_TRIANGLES, context->batch.EBOcount, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);

    RenderBatchReset(&context->batch);
}