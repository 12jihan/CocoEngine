#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


// Vertex Shader source code
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

//Fragment Shader source code
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
"}\n\0";


int main(int argc, char const *argv[])
{   
    // Initialize glfw library:
    glfwInit();

    // Clarifying the version of glfw library:
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    // Tell glfw we are using the core profile with only modern functions:
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create window object:
    GLFWwindow* window = glfwCreateWindow(800, 800, "fucking window", NULL, NULL);
    // Check to see if window was properly created:
    if (window == NULL)
    {
        std::cout << "Failed to create window" << std::endl;
        glfwTerminate();
        return -1;
    } 

    // Introduce the window into the current context:
    glfwMakeContextCurrent(window);
    gladLoadGL();

    // Describing the viewport of the window:
    glViewport(0, 0, 800, 800);

    // Specify the background color of the window:
    glClearColor(1.0f, 0.13f, 0.17f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Add window into the program:
    glfwSwapBuffers(window);

    // Loop for the frames:
    while(!glfwWindowShouldClose(window))
    {
        // Gets all events happening to the window:
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}