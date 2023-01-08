cmake_minimum_required(VERSION 3.0.0)
project(CocoEngine VERSION 0.1.0)

include(CTest)
enable_testing()

# Download all the submodules
# find_package(Git QUIET)
# if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
#     #Update submodules as needed
#     option(GIT_SUBMODULE "check submodules during build" ON)
#     if(GIT_SUBMODULE)
#         message(STATUS "Submodule update")
#         execute_process(COMMAND ${GIT_EXECUTABLE} submodules update --init --recursive WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} RESULT_VARIABLE GIT_SUBMOD_RESULT)
#     endif()
# endif()

# #               CHECK ALL THE SUBMODULES
# if(NOT EXISTS "${PROJECT_SOURCE_DIR}/external/glfw/CMakeLists.txt")
#     message(FATAL_ERROR "The glfw submodules was nod downloaded! GIT_SUBMODULE was turned off or failed. Please update sobmodule and try again.")
# endif()

add_executable(${PROJECT_NAME} main.cpp)
add_subdirectory(external/glfw)

target_include_directories(${PROJECT_NAME} 
    PUBLIC external/glfw/include
)

target_link_directories(${PROJECT_NAME} 
    PUBLIC external/glfw/src
)

target_link_libraries(${PROJECT_NAME} 
    glfw
)
