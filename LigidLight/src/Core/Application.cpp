#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Application.hpp"
#include "Gl.hpp"

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);



void LigidL::run()
{
    
    Gl gl;
    gl.glfwInitializeAndConfigure();
    
    GLFWwindow* window;
    window = gl.glfwCreateTheWindow();

    gl.loadGl();

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        processInput(window);

        // render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    glfwTerminate();
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
void processInput(GLFWwindow *window)
{

}