#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Application.hpp"
#include "Gl.hpp"
#include "Util.hpp"
#include "ColorPalette.hpp"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtx/string_cast.hpp"

#include <iostream>

void processInput(GLFWwindow *window);

void LigidL::run()
{
    Util util;
    ColorPalette colorPalette;
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
        glClearColor(colorPalette.bgColor[0],colorPalette.bgColor[1],colorPalette.bgColor[2],1.0f);
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