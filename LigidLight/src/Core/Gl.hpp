#ifndef LGDLGHT_GL_HPP
#define LGDLGHT_GL_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Gl
{
public:
    void glfwInitializeAndConfigure();
    GLFWwindow* glfwCreateWindow();
    void loadGl();
};

#endif