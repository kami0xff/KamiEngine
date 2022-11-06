#pragma once 


#include <glad/glad.h>
#include <GLFW/glfw3.h>
class KamiGlfwWindow {
public:
	GLFWwindow* m_window;
	void init();
	void create(unsigned int, unsigned int);
	void processInput();
};