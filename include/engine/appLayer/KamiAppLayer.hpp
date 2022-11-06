
#include "KamiTextRessources.hpp"
#include "random/KamiRandom.hpp"
#include "KamiClientOptions.hpp"
#include "platform/KamiGlfwWindow.hpp"

class KamiAppLayer {

public:

	KamiTextRessources m_textRessources;
	KamiClientOptions m_clientOptions; //get loading and saving of options to work
	KamiRandom m_randomNumberGenerator;

//what if i want to use other windows 
#define GLFW_WINDOW
#ifdef GLFW_WINDOW
	KamiGlfwWindow m_glfwWindow;
#endif

	void initialiseAppLayer();

	//Window
	//KamiGameLayer ?
	///KamiViewLayer ?
	//KamiEventSystem



};