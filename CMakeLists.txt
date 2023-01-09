cmake_minimum_required(VERSION 3.0.0)
project(CocoEngine VERSION 0.1.0)


add_executable(${PROJECT_NAME} 
    src/main.cpp
    src/glad.c
    src/Shader.cpp
    src/VAO.cpp
    src/VBO.cpp
    src/EBO.cpp
    src/stb.cpp
)

add_subdirectory(
    external/glfw
    external/glad
    )

target_include_directories(${PROJECT_NAME} 
    PUBLIC external/glfw/include
    PUBLIC external/glad/include
    PUBLIC external/stb/include
)

target_link_directories(${PROJECT_NAME} 
    PUBLIC external/glfw/src
)

target_link_libraries(${PROJECT_NAME} 
    glfw
    # glad
)
