#include "input.h"
#include <GLFW/glfw3.h>
#include <stdint.h>

int32_t InputKeyState(void* window, int32_t keycode) {
    return glfwGetKey((GLFWwindow*) window, keycode);
}
