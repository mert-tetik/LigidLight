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

#include <vector>

void processInput(GLFWwindow *window);
void mouseCallback(GLFWwindow* window, double xpos, double ypos);

glm::vec2 mousePos = {0,0}; //Cursor pos in the window

void LigidL::run()
{
    Util util;
    ColorPalette colorPalette;
    Gl gl;
    gl.glfwInitializeAndConfigure();
    
    GLFWwindow* window;
    window = gl.glfwCreateTheWindow();

    gl.loadGl();
    
    Programs programs = gl.getPrograms();

    glm::mat4 uiProjection = glm::ortho(0,1,0,1);

    float vertices[] = {
        // first triangle
         0.5f,  0.5f, 0.0f,  // top right
         0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f,  0.5f, 0.0f,  // top left 
        // second triangle
         0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f   // top left
    }; 

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0); 
  
    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0); 


    glUseProgram(programs.UIProgram);
    gl.uniformMatrix4fv(programs.UIProgram,"projection",uiProjection);
    
    glm::vec4 titleBarclr;
    titleBarclr.r = colorPalette.titleBarColor[0];
    titleBarclr.g = colorPalette.titleBarColor[1];
    titleBarclr.b = colorPalette.titleBarColor[2];
    titleBarclr.a = 1.f;
    
    gl.uniform4fv(programs.UIProgram,"color",titleBarclr);

    glfwSetCursorPosCallback(window, mouseCallback);

    // render loop
    // -----------

    while (!glfwWindowShouldClose(window))
    {
        // input
        processInput(window);

        // render
        glClearColor(colorPalette.bgColor[0],colorPalette.bgColor[1],colorPalette.bgColor[2],1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        gl.windowFollowTheCursor(window);

        glUseProgram(programs.UIProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    glfwTerminate();
}

void mouseCallback(GLFWwindow* window, double xpos, double ypos){
    mousePos.x = xpos;
    mousePos.y = ypos;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
void processInput(GLFWwindow *window)
{

}