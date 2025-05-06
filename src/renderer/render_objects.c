#include "render_objects.h"
#include "vertex.h"
#include "vendor/glad/gl.h"
#include <stdlib.h>

struct RenderObjects {
    uint32_t VAO;
    uint32_t VBO;
    uint32_t EBO;
};

RenderObjects* RenderObjectsInit() {
    RenderObjects* r = (RenderObjects*) malloc(sizeof(struct RenderObjects));

    glGenVertexArrays(1, &(r->VAO));
    glGenBuffers(1, &(r->VBO));
    glGenBuffers(1, &(r->EBO));

    glBindVertexArray(r->VAO);
    
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) 0);
    glEnableVertexAttribArray(0);
    
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(float) * 2));
    glEnableVertexAttribArray(1);
    
    glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(float) * 4));
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ARRAY_BUFFER, r->VBO);
    glBufferData(GL_ARRAY_BUFFER, 0, NULL, GL_DYNAMIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, r->EBO);
    glBufferData(GL_ARRAY_BUFFER, 0, NULL, GL_DYNAMIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    return r;
}

void RenderObjectsDestroy(RenderObjects* renderer) {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glDeleteBuffers(1, renderer->VBO);
    glDeleteBuffers(1, renderer->EBO);
    glDeleteVertexArrays(1, renderer->VAO);
    free(renderer);
}