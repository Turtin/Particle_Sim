#include <cmath>
#include <iostream>
#include <vector>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "shaders/LoadShaders.h"

void drawCircle(float cx, float cy, float r) {
    int segments = 50;

    std::pmr::vector<float> vertices = {};

    vertices.push_back(cx);
    vertices.push_back(cy);

    for (int i = 0; i <= segments; i++) {
        float theta = 2 * M_PI / segments;
        float x = cosf(theta * i) * r * 3/4;
        float y = sinf(theta * i) * r;

        vertices.push_back(x + cx);
        vertices.push_back(y + cy);
    }

    unsigned int VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(0);

    glDrawArrays(GL_TRIANGLE_FAN, 0, segments + 2);

    glBindVertexArray(0);
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

int main() {
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    GLFWwindow *window = glfwCreateWindow(800, 600, "Simulation", nullptr, nullptr);

    glfwMakeContextCurrent(window);
    gladLoadGL();
    // init shaders
    unsigned int shaderProgram = LoadShaders::loadShaders("glsl/vertex.glsl", "glsl/fragment.glsl");

    while (!glfwWindowShouldClose(window)) {
        double mouseX, mouseY;
        glfwGetCursorPos(window, &mouseX, &mouseY);

        float ndcX = (static_cast<float>(mouseX) / 800.0f) * 2.0f - 1.0f;
        float ndcY = 1.0f - (static_cast<float>(mouseY) / 600.0f) * 2.0f;

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        drawCircle(ndcX, ndcY, 0.1f);
        glfwSwapBuffers(window);

        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}
