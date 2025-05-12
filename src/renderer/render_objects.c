#include "render_objects.h"
#include "vertex.h"
#include "render_batch.h"
#include "vendor/glad/gl.h"

RenderObjects RenderObjectsInit() {
    RenderObjects r = { 0 };

    glGenVertexArrays(1, &r.VAO);
    glGenBuffers(1, &r.VBO);
    glGenBuffers(1, &r.EBO);

    glBindVertexArray(r.VAO);

    glBindBuffer(GL_ARRAY_BUFFER, r.VBO);
    glBufferData(GL_ARRAY_BUFFER, 0, NULL, GL_DYNAMIC_DRAW);
    
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) 0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(float) * 2));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(float) * 4));
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, r.EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 0, NULL, GL_DYNAMIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    return r;
}

void RenderObjectsFlushVBO(RenderObjects* ro, RenderBatch* rb) {
    glBindBuffer(GL_ARRAY_BUFFER, ro->VBO);
    glBufferData(GL_ARRAY_BUFFER, rb->VBOcount * sizeof(float), rb->VBOdata, GL_DYNAMIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void RenderObjectsFlushEBO(RenderObjects* ro, RenderBatch* rb) {
    glBindVertexArray(ro->VAO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ro->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, rb->EBOcount * sizeof(uint32_t), rb->EBOdata, GL_DYNAMIC_DRAW);
    glBindVertexArray(0);
}

void RenderObjectsDestroy(RenderObjects* renderer) {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glDeleteBuffers(1, &renderer->VBO);
    glDeleteBuffers(1, &renderer->EBO);
    glDeleteVertexArrays(1, &renderer->VAO);
}
