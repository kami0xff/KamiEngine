#include <platform/glfw_window.hpp>
#include <stdexcept>

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void KamiGlfwWindow::processInput()
{
	if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(m_window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}


void KamiGlfwWindow::init() {
	if (!glfwInit())
		throw std::runtime_error("GLFW failed to initialize.");
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}


void KamiGlfwWindow::create() {

	m_window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
	if (m_window == NULL)
	{
		//std::cout << "Failed to create GLFW window" << std::endl;
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

	glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);
}