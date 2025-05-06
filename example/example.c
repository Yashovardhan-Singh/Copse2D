#include "../src/window/window.h"

#define NULL ((void*)0)

int main() {
    Window* w = WindowInit(1280, 720, "Test", NULL);
    while (!WindowCloseEvent(w)) {
        WindowRefresh(w);
    }
    return 0;
}