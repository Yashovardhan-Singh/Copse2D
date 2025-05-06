#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>

#include "window.h"
#include "../../vendor/tomlc/toml.h"

struct Window {
    GLFWwindow* handle;
    const char* title;
    uint32_t width, height;
};

// Refactor this shit
Window* WindowInit(uint32_t width, uint32_t height, const char* title, const char* settingsFilePath) {
    Window* win = calloc(1, sizeof(Window));

    uint32_t fullscreen = 0;

    if (settingsFilePath != NULL) {
        FILE* settingsFilePointer = fopen(settingsFilePath, "r");
        toml_table_t* root = toml_parse_file(settingsFilePointer, NULL, 0);
        fclose(settingsFilePointer);

        int32_t flags = 0;
        toml_table_t* display = toml_table_in(root, "display");

        // add more hints ig?
        if (toml_bool_in(display, "resizeable").u.b != 0) glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
        if (toml_bool_in(display, "borderless").u.b != 0) glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
        if (toml_bool_in(display, "cursor").u.b == 0) glfwWindowHint(GLFW_CURSOR, GLFW_FALSE);
        if (toml_bool_in(display, "fullscreen").u.b != 0) fullscreen = 1;
    }
    
    glfwInit();

    win->width = width;
    win->height = height;
    win->title = title;

    if (fullscreen)
        win->handle = glfwCreateWindow(width, height, title, glfwGetPrimaryMonitor(), NULL);
    else
        win->handle = glfwCreateWindow(width, height, title, NULL, NULL);

    glfwMakeContextCurrent(win->handle);

    return win;
}

uint32_t WindowCloseEvent(Window* window) {
    return glfwWindowShouldClose(window->handle);
}

void WindowRefresh(Window* window) {
    glfwSwapBuffers(window->handle);
    glfwPollEvents();
}

void WindowDestroy(Window* window) {
    glfwDestroyWindow(window->handle);
    free(window);
    glfwTerminate();
}