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
	KamiClientOptions::getInstance().readClientOptionsJson();

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

	//should initialize the game state game logic and view attached to the game logic 

	//actually i have a bug in the destructor if my texture class right now where i call the stb free method 
	//in the destructor but closing the window and not the program will cause an exception

}