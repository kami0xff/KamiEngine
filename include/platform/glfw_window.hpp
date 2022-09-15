#pragma once 


#include <glad/glad.h>
#include <GLFW/glfw3.h>
class KamiGlfwWindow {
public:
	GLFWwindow* m_window;
	void init();
	void create();
	void processInput();
private:
	const unsigned int SCR_HEIGHT = 600;
	const unsigned int SCR_WIDTH = 800;
};