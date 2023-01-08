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
find_library( GLUT_glut_LIBRARY NAMES glut glut32 freeglut
    PATHS
    ${OPENGL_LIBRARY_DIR}
    ${GLUT_ROOT_PATH}/Release
    )
add_executable(${PROJECT_NAME} main.cpp)
add_subdirectory(
    external/glfw
    external/glad
)

target_include_directories(${PROJECT_NAME} 
    PUBLIC external/glfw/include
    # PUBLIC external/glad/include
    # ${OPENGL_INCLUDE_DIRS}
)

target_link_directories(${PROJECT_NAME} 
    PUBLIC external/glfw/src
    # PUBLIC external/glad
)

target_link_libraries(${PROJECT_NAME} 
    glfw
    # glad
    # ${OPENGL_LIBRARIES}
)
