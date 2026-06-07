#include <iostream>

#include "GLFW/glfw3.h"

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    while (true) {
        std::cout << "running";
    }
    return 0;
}
