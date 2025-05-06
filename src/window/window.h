#ifndef WINDOW_H
#define WINDOW_H

#include <stdint.h>

typedef struct Window Window;

Window* WindowInit(uint32_t width, uint32_t height, const char* title, const char* fileSettingsPath);
uint32_t WindowCloseEvent(Window* window);
void WindowRefresh(Window* window);
void WindowDestroy(Window* window);

#endif