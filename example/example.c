#include "../src/window/window.h"
#include "../src/renderer/renderer.h"
#include <stdio.h>

#include "gl.h"

#define NULL ((void*)0)

int main() {
    Window* w = WindowInit(1280, 720, "Test", NULL);
    Texture t = TextureCreate("../example/test.png");
    RenderContext* rctx = RenderContextInit();
    RObject o = (RObject) {
        .x1 = 0.0, .y1 = 0.0, .x2 = 1.0, .y2 = 1.0,
        .u1 = 0.0, .u2 = 0.0, .v1 = 1.0, .v2 = 1.0,
        .color = (Color) { 1.0, 1.0, 1.0, 1.0 },
        .tex = t
    };
    RObject o2 = (RObject) {
        .x1 = -1.0, .y1 = -1.0, .x2 = 0.0, .y2 = 0.0,
        .u1 = 0.0, .u2 = 0.0, .v1 = 1.0, .v2 = 1.0,
        .color = (Color) { 0.5, 0.5, 0.5, 1.0 },
        .tex = t
    };
    int fc = 0;
    while (!WindowCloseEvent(w)) {
        glClearColor(0.0, 0.0, 0.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        DrawObject(rctx, &o);
        DrawObject(rctx, &o2);
        WindowRefresh(w);
    }
    TextureDestroy(t);
    RenderContextDestroy(rctx);
    return 0;
}