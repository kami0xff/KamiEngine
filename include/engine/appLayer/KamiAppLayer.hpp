
#include "KamiTextRessources.hpp"
#include "random/KamiRandom.hpp"
#include "KamiClientOptions.hpp"
#include "platform/KamiGlfwWindow.hpp"
#include "engine/cache/KamiRessourceCache.hpp"

class KamiAppLayer {

private:
	KamiAppLayer() {};
	KamiAppLayer& operator=(const KamiAppLayer&);  // Leave unimplemented
	KamiAppLayer(const KamiAppLayer&);


public:
	static KamiAppLayer& getInstance();

	
	//for now text outside the general ressource cache
	//KamiRessourceCache m_ressourceCache{}; //calling default constructor made private in the kamiressource cache class because 
	//i made it a singleton TODO refactor all constructors !!!!!

	//so maybe move these into singletons and in the intialise i initialise all the singletons in my application 
	//but i still want to keep random number and the window in here but text ressources not really 
	//and client options also no really 


	KamiRandom m_randomNumberGenerator{};

#define GLFW_WINDOW
#ifdef GLFW_WINDOW
	KamiGlfwWindow m_glfwWindow{};
#endif

	void initialiseAppLayer();

	//Window
	//KamiGameLayer ?
	///KamiViewLayer ?
	//KamiEventSystem



};