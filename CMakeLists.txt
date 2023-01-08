cmake_minimum_required(VERSION 3.0.0)
project(CocoEngine VERSION 0.1.0)
# set(OpenGL_GL_PREFERENCE "GLVND")
# find_package(OpenGL REQUIRED COMPONENTS OpenGL)
# if(OPENGL_FOUND)
#     message("Found OpenGL in the current environment!")
# else()
#     message("Error: No OpenGL found.")
# endif()
# message("OpenGL include dirs: " )
# message("\tdir: ${OPENGL_INCLUDE_DIR}")
# message("\tlib: ${OPENGL_LIBRARIES} ")

add_executable(${PROJECT_NAME} 
    main.cpp 
    external/glad/src/glad.c
)
# find_package(OpenGL REQUIRED)
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
    PUBLIC external/glad/src
)

target_link_libraries(${PROJECT_NAME} 
    glfw
)
