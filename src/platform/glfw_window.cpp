#include <platform/glfw_window.hpp>
#include <stdexcept>

void KamiGlfwWindow::processInput()
{
	if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(m_window, true);

	//input system and camera system coupling sounds bad but input needs to be fast 
	//how do i want to deal with input anyways in this game engine ??


	//if glfwGetKey x trigger event from input event system x 

	//kamiInputEventSystem into a singleton and then use its static methods ?
	//and make sure that the instance is create at engine init ??
	//
	if (glfwGetKey(m_window, GLFW_KEY_W) == GLFW_PRESS)
	{
		//sent notify the listeners with the proper event 
	}
	if (glfwGetKey(m_window, GLFW_KEY_S) == GLFW_PRESS) {}
	if (glfwGetKey(m_window, GLFW_KEY_A) == GLFW_PRESS) {}
	if (glfwGetKey(m_window, GLFW_KEY_D) == GLFW_PRESS) {}



}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}


void KamiGlfwWindow::init() {
	if (!glfwInit())
		throw std::runtime_error("GLFW failed to initialize.");
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}


void KamiGlfwWindow::create() {

	m_window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
	if (m_window == NULL)
	{
		throw std::runtime_error("Failed to create GLFW Window");
		glfwTerminate();
	}
	glfwMakeContextCurrent(m_window);

	// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		throw std::runtime_error("Failed to load GLAD");
	}

	//not sure if this would be usefull to make sure gl functions are not called until this is defined
#define KAMI_GLAD_LOADED

	glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);
}