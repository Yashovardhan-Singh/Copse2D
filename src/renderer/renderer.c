#include "renderer.h"
#include "vertex.h"
#include "../../vendor/glad/gl.h"
#include <math.h>

// Internal 2D Transform Struct
typedef struct {
    float x, y;       // Position
    float rotation;   // Radians
    float sx, sy;     // Scale
} Transform2D;

// Create A 2D Affine Transform Matrix (3x2) From Transform2D
static void makeTransformMatrix(const Transform2D* t, float out[6]) {
    float c = cosf(t->rotation);
    float s = sinf(t->rotation);

    out[0] =  c * t->sx; // a
    out[1] =  s * t->sx; // b
    out[2] = -s * t->sy; // c
    out[3] =  c * t->sy; // d
    out[4] = t->x;       // tx
    out[5] = t->y;       // ty
}

// Apply 3x2 Affine Matrix To 2D Point
static void applyTransform(float x, float y, const float mat[6], float* outX, float* outY) {
    *outX = mat[0] * x + mat[2] * y + mat[4];
    *outY = mat[1] * x + mat[3] * y + mat[5];
}

void RendererStartFrame(Color color) {
    glClearColor(color.r, color.g, color.b, color.a);
    glClear(GL_COLOR_BUFFER_BIT);
}

void RendererDrawObject(RenderContext* context, RObject* obj) {
    // Compute Quad Center
    float cx = obj->x + obj->w * 0.5f;
    float cy = obj->y + obj->h * 0.5f;

    // Local Quad Vertices Centered At (0, 0)
    float local[4][2] = {
        { -obj->w * 0.5f, -obj->h * 0.5f },
        {  obj->w * 0.5f, -obj->h * 0.5f },
        { -obj->w * 0.5f,  obj->h * 0.5f },
        {  obj->w * 0.5f,  obj->h * 0.5f }
    };

    // Setup Transform
    Transform2D t = { cx, cy, obj->rotation, obj->scaleX, obj->scaleY };
    float mat[6];
    makeTransformMatrix(&t, mat);

    // Transform Vertices
    float world[4][2];
    for (int i = 0; i < 4; ++i) {
        applyTransform(local[i][0], local[i][1], mat, &world[i][0], &world[i][1]);
    }

    // Texture Coordinate Extents
    float u2 = obj->u + obj->tw;
    float v2 = obj->v + obj->th;

    // Define Vertex Attributes In Proper Order (CCW)
    Vertex vertices[4] = {
        { world[0][0], world[0][1], obj->u, v2, obj->color.r, obj->color.g, obj->color.b, obj->color.a },
        { world[1][0], world[1][1], u2, v2, obj->color.r, obj->color.g, obj->color.b, obj->color.a },
        { world[2][0], world[2][1], obj->u, obj->v, obj->color.r, obj->color.g, obj->color.b, obj->color.a },
        { world[3][0], world[3][1], u2, obj->v, obj->color.r, obj->color.g, obj->color.b, obj->color.a }
    };

    // Push To Batch
    for (int i = 0; i < 4; ++i) {
        RenderBatchAddVertex(&context->batch, vertices[i]);
    }
    RenderBatchUpdateQuadIndices(&context->batch);
}

void RendererStopFrame(RenderContext* context) {
    RenderObjectsFlushVBO(&context->renderer, &context->batch);
    RenderObjectsFlushEBO(&context->renderer, &context->batch);

    ShaderUse(context->shader);
    glBindVertexArray(context->renderer.VAO);
    glDrawElements(GL_TRIANGLES, context->batch.EBOcount, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);

    RenderBatchReset(&context->batch);
}
