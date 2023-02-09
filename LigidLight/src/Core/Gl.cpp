#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Application.hpp"
#include "Gl.hpp"
#include "Util.hpp"

#include <iostream>

void Gl::glfwInitializeAndConfigure(){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif
}
GLFWwindow* Gl::glfwCreateTheWindow(){
    const unsigned int SCR_WIDTH = 800;
    const unsigned int SCR_HEIGHT = 600;
    // glfw window creation
    // --------------------

    glfwWindowHint(GLFW_DECORATED, false);//Remove title bar

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);

    return window;
}

void Gl::loadGl(){
    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }    
}


void testShader(unsigned int shader,const char* path){
	int success;
	char infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << path << ' ' << infoLog << ' '  << shader << std::endl;
	};
}
unsigned int createShader(const char* path,unsigned int shaderType){
	Util utilities;
	std::string shaderText = utilities.readFile(path);
	const char* shaderSource = shaderText.c_str();

	unsigned int shader = glCreateShader(shaderType);
	glShaderSource(shader, 1, &shaderSource, NULL);
	glCompileShader(shader);
	testShader(shader,path);
	return shader;
}

unsigned int createProgram(std::string path){
	unsigned int vertexShader = createShader((path + ".vert").c_str(),GL_VERTEX_SHADER);
	unsigned int fragmentShader = createShader((path + ".frag").c_str(),GL_FRAGMENT_SHADER); 

	unsigned int program = glCreateProgram();
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);
	glLinkProgram(program);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	return program;
}

Programs getPrograms(){
    Programs programs;
    programs.UIProgram = createProgram("LigidLight/resources/Shaders/ui");
}