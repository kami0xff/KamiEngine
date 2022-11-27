#include "engine/appLayer/KamiAppLayer.hpp"
#include <iostream>

KamiAppLayer& KamiAppLayer::getInstance() 
{
	static KamiAppLayer instance;
	return instance;

}

void KamiAppLayer::initialiseAppLayer() 
{
	//should initalize ressources here textures obj files sounds 
	//map infomration 
	//singletons
	KamiRessourceCache::getInstance().loadEntityRessources();
	KamiRessourceCache::getInstance().loadVertexShaderRessources();
	KamiRessourceCache::getInstance().loadFragmentShaderRessources();
	KamiClientOptions::getInstance().readClientOptionsJson();
	//loads raw ressource data
	KamiRessourceCache::getInstance().loadTextures();


	m_randomNumberGenerator.test();
	
	//text does not need initialization already in memory
	std::cout << "text ressource test: " << KamiTextRessources::getInstance().getString("TEST") << "\n";
	
	//TODO
	//we try to initialize DirectX here if DX_WINDOWS is defined 
	


#ifdef GLFW_WINDOW
	//opengl also gets initialized
	m_glfwWindow.init();
	//can i store temp pointer ? to make this less verbose ? TODO
	m_glfwWindow.create(KamiClientOptions::getInstance().m_screenWidth, KamiClientOptions::getInstance().m_screenHeight);
#endif

	//requires OPENGL function to be LOADED
	KamiRessourceCache::getInstance().createShaderPrograms();


}