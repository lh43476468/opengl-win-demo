#ifndef BUILD_WITH_SHARE_LIB
    #define GLEW_STATIC
#endif

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <vector>

int main(){

    int WIDTH = 800, HEIGHT = 600;
    GLFWwindow* window;
    /* Initialize the library */
    if (!glfwInit())
        return -1;
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(WIDTH, HEIGHT, "hello opengl test", NULL, NULL);
    if (!window){
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // tell the GLFW to caputure mouse
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    /*glewInit();*/
    if (glewInit() != GLEW_OK)
        std::cout << "ERROR ON GLEWINIT" << std::endl;

    std::cout << glGetString(GL_VERSION) << std::endl;

    while( !glfwWindowShouldClose(window)){

        glClearColor(1.f, 1.f, 0.5f, 0.f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // draw something there

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}