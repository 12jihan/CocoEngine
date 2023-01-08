#include <iostream>
#include <GLFW/glfw3.h>

int main(int argc, char const *argv[])
{

    GLFWwindow* window;
    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        exit( EXIT_FAILURE );
    }

    window = glfwCreateWindow(300, 300, "CocoEngine", NULL, NULL);
    if (!window)
    {
        fprintf( stderr, "Failed to open GLFW window\n" );
        glfwTerminate();
        exit( EXIT_FAILURE );
    }

    // Main loop:
    while(!glfwWindowShouldClose(window)) 
    {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    

    //Terminate GLFW window:
    glfwTerminate();




    return 0;
}
