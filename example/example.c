#include "../src/window/window.h"
#include "../src/renderer/renderer.h"

#define DEG2RAD 0.01745329251   // Debug constant

int main() {

    Window* w = WindowInit(1280, 720, "Test", NULL);
    RenderContext* rctx = RenderContextInit();

    Texture t = TextureCreate("../example/test.png");   // Binds texture too
    Texture t2 = TextureCreate("../example/test.jpg");

    TextureBind(t);

    RObject o = (RObject) {
        .x = -0.5, .y = -0.5,
        .w = 1.0, .h = 1.0,
        .u = 0.0, .v = 0.0,
        .tw = 1.0, .th = 1.0,
        .color = WHITE,
        .scaleX = 1.0, .scaleY = 1.0,
        .rotation = 0 * DEG2RAD,
    };

    while (!WindowCloseEvent(w)) {
        o.rotation += DEG2RAD * 1.0;

        RendererStartFrame((Color) {0.0, 0.0, 0.0, 1.0});
            RendererDrawObject(rctx, &o);
        RendererStopFrame(rctx);

        WindowRefresh(w);
    }

    TextureDestroy(t);
    TextureDestroy(t2);

    RenderContextDestroy(rctx);

    return 0;
}