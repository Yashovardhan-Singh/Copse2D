#ifndef RENDER_OBJECTS_H
#define RENDER_OBJECTS_H

typedef struct RenderObjects RenderObjects;

RenderObjects* RenderObjectsInit();
void RenderObjectsDestroy(RenderObjects* renderer);

#endif