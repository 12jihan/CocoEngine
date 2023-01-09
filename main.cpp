#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <math.h>

// Vertex Shader source code
const char *vertexShaderSource = "#version 330 core\n"
                                 "layout (location = 0) in vec3 aPos;\n"
                                 "void main()\n"
                                 "{\n"
                                 "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                 "}\0";

// Fragment Shader source code
const char *fragmentShaderSource = "#version 330 core\n"
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
    GLFWwindow *window = glfwCreateWindow(800, 800, "fucking window", NULL, NULL);
    // Check to see if window was properly created:
    if (window == NULL)
    {
        std::cout << "Failed to create window" << std::endl;
        glfwTerminate();
        return -1;
    };

    // Introduce the window into the current context:
    glfwMakeContextCurrent(window);
    
    //Load GLAD so it configures OpenGL
	gladLoadGL();

    // Describing the viewport of the window:
    glViewport(0, 0, 800, 800);

    //~~ creating shaders and what not:
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

     GLfloat vertices[] = {
        -0.5f,   -0.5f * float(sqrt(3)) / 3,     0.0f,
         0.5f,   -0.5f * float(sqrt(3)) / 3,     0.0f, 
         0.0f,    0.5f * float(sqrt(3)) * 2 / 3, 0.0f,
    };

    //~~ Creating Buffers:
    GLuint vao, vbo;

    glGenVertexArrays(1, &vao);
    // Creating 1 Buffer object for vbo:
    glGenBuffers(1, &vbo);

    // bind vao:
    glBindVertexArray(vao);

    // Binding to make the current(binded) object visible:
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    // store vertices in the vbo:
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // communicate with the vertex shader from the outside:
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);


    // Add window into the program:
    glfwSwapBuffers(window);

    // Loop for the frames:
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(1.0f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(shaderProgram);
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glfwSwapBuffers(window);
        // Gets all events happening to the window:
        glfwPollEvents();

    }

    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteProgram(shaderProgram);

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}