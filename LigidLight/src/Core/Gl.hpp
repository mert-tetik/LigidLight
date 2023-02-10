#ifndef LGDLGHT_GL_HPP
#define LGDLGHT_GL_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtx/string_cast.hpp"

class Gl
{
public:
    void glfwInitializeAndConfigure();
    GLFWwindow* glfwCreateTheWindow();
    void loadGl();
    Programs getPrograms();
    glm::vec2 getScreenCursorPos();
    void windowFollowTheCursor(GLFWwindow* window);


    void uniform4fv(unsigned int program, const char* target, glm::vec4 &vectorValue);  
    void uniformMatrix4fv(unsigned int program, const char* target, glm::mat4x4 matrixVal);
};

#endif