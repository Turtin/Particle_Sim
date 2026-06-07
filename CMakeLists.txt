cmake_minimum_required(VERSION 4.0)
project(Particle_Sim)

include(FetchContent)

set(CMAKE_CXX_STANDARD 20)

FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG        3.4
        GIT_SHALLOW    TRUE
)

FetchContent_Declare(
        glm
        GIT_REPOSITORY https://github.com/g-truc/glm.git
        GIT_TAG        1.0.1 # Stable release version
        GIT_SHALLOW    TRUE
)

FetchContent_MakeAvailable(glfw glm)

find_package(OpenGL REQUIRED)

add_executable(Particle_Sim main.cpp)

target_link_libraries(Particle_Sim
        PRIVATE
        OpenGL::GL
        glm
        glfw
)