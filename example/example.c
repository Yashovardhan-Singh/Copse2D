#include "../src/window/window.h"
#include "../src/renderer/renderer.h"
#include "../src/input/input.h"

#include <stdio.h>

#define DEG2RAD 0.01745329251   // Debug constant

int main() {

    Window* w = WindowInit(800, 800, "Test", NULL);
    RenderContext* rctx = RenderContextInit();

    Texture t = TextureCreate("../../example/assets/test.png");   // Binds texture too
    Texture t2 = TextureCreate("../../example/assets/test.jpg");

    TextureBind(t);

    RObject o = (RObject) {
        .x = -0.5, .y = -0.5,
        .w = 0.1, .h = 0.1,
        .u = 0.0, .v = 0.0,
        .tw = 1.0, .th = 1.0,
        .color = WHITE,
        .scaleX = 1.0, .scaleY = 1.0,
        .rotation = 0 * DEG2RAD,
    };

    Shader cs = ShaderCreateFromFiles("../../example/shaders/efrag.glsl", "../../example/shaders/evert.glsl");
    rctx->shader = cs;

    rctx->camera.zoom = 0.3;

    while (!WindowCloseEvent(w)) {
        if (InputKeyState(WindowGetHandle(w), KEY_ESCAPE)) {
            break;
        }

        if (InputKeyState(WindowGetHandle(w), KEY_W)) {
            o.y += 0.01;
        }

        if (InputKeyState(WindowGetHandle(w), KEY_A)) {
            o.x -= 0.01;
        }

        if (InputKeyState(WindowGetHandle(w), KEY_S)) {
            o.y -= 0.01;
        }

        if (InputKeyState(WindowGetHandle(w), KEY_D)) {
            o.x += 0.01;
        }

        o.rotation += DEG2RAD * 1.0;

        RendererStartFrame(WHITE);
            RendererDrawObject(rctx, &o);
        RendererStopFrame(rctx);

        WindowRefresh(w);
    }

    TextureDestroy(t);
    TextureDestroy(t2);

    RenderContextDestroy(rctx);

    return 0;
}