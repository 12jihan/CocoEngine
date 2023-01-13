cmake_minimum_required(VERSION 3.0.0)
project(CocoEngine VERSION 0.1.0)

file(COPY src/resources DESTINATION ${CMAKE_BINARY_DIR}) 
file(COPY src/shaders DESTINATION ${CMAKE_BINARY_DIR}) 
file(GLOB INC_SRC
    external/glfw/include
    external/glad/include
    external/stb/include
    external/glm
    external/json/include
)

file(GLOB HEADER_FILES
    src/headers/*.h
)

file(GLOB ALL_CLASSES
    src/*.c
    src/*.cpp
)

# file(GLOB SUB_DIR 
#     external/glfw
#     external/glad
# )

add_executable(${PROJECT_NAME} 
    ${ALL_CLASSES}
)

add_subdirectory(
    external/glfw
    external/glad
    )

# target_include_directories(${PROJECT_NAME} 
#     PUBLIC external/glfw/include
#     PUBLIC external/glad/include
#     PUBLIC external/stb/include
# )

target_include_directories(${PROJECT_NAME} 
    PUBLIC ${INC_SRC}
)

target_link_directories(${PROJECT_NAME} 
    PUBLIC external/glfw/src
)

target_link_libraries(${PROJECT_NAME} 
    glfw
)
