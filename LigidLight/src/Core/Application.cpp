#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Application.hpp"
#include "Gl.hpp"
#include "Util.hpp"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtx/string_cast.hpp"

#include <iostream>

void processInput(GLFWwindow *window);

void LigidL::run()
{
    Util util;
    
    Gl gl;
    gl.glfwInitializeAndConfigure();
    
    GLFWwindow* window;
    window = gl.glfwCreateTheWindow();

    gl.loadGl();
    
    glm::vec3 bgColor = glm::vec3(227,231,233);
    bgColor = util.vec3RGBscaleTo1(bgColor);
    
    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        processInput(window);

        // render
        glClearColor(bgColor.r,bgColor.g,bgColor.b,1.0f);
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