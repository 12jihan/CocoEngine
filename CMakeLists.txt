cmake_minimum_required(VERSION 3.0.0)
project(CocoEngine VERSION 0.1.0)


add_executable(${PROJECT_NAME} 
    src/main.cpp
    src/glad
)

add_subdirectory(
    external/glfw
    external/glad
)

target_include_directories(${PROJECT_NAME} 
    PUBLIC external/glfw/include
    PUBLIC external/glad/include
)

target_link_directories(${PROJECT_NAME} 
    PUBLIC external/glfw/src
    PUBLIC src/glad
)

target_link_libraries(${PROJECT_NAME} 
    glfw
    # glad
)
