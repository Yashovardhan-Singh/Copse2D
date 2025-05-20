#include "../../vendor/glad/gl.h"
#include <GLFW/glfw3.h>
#include <stdlib.h>

#include "window.h"
#include "../../vendor/tomlc/toml.h"

struct Window {
    GLFWwindow* handle;
    const char* title;
    uint32_t width, height;
};

static void _framebuffer_size_callback(GLFWwindow* glfw_win, int width, int height) {
    // Retrieve the Window struct from the user pointer
    Window* win = (Window*)glfwGetWindowUserPointer(glfw_win);

    // Update width and height
    win->width = (uint32_t)width;
    win->height = (uint32_t)height;

    // Update the OpenGL viewport
    glViewport(0, 0, win->width, win->height);
}

// TODO: Refactor this shit
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

        toml_free(root);
    }

    glfwInit();

    win->width = width;
    win->height = height;
    win->title = title;

    if (fullscreen)
        win->handle = glfwCreateWindow(width, height, title, glfwGetPrimaryMonitor(), NULL);
    else
        win->handle = glfwCreateWindow(win->width, win->height, win->title, NULL, NULL);

    glfwMakeContextCurrent(win->handle);

    glfwSetWindowUserPointer(win->handle, win);
    glfwSetFramebufferSizeCallback(win->handle, _framebuffer_size_callback);

    gladLoadGL(glfwGetProcAddress);

    int fbWidth, fbHeight;
    glfwGetFramebufferSize(win->handle, &fbWidth, &fbHeight);
    glViewport(0, 0, fbWidth, fbHeight);

    return win;
}

void* WindowGetHandle(Window* window) {
    return window->handle;
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