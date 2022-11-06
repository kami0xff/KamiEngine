#include "engine/appLayer/KamiAppLayer.hpp"
#include <iostream>
void KamiAppLayer::initialiseAppLayer() 
{
	//should initalize ressources here textures obj files sounds 
	//map infomration etc



	m_clientOptions.readClientOptionsJson();
	m_randomNumberGenerator.test();
	std::cout << "text ressource test: " << m_textRessources.getString("TEST") << "\n";
	
	//TODO
	//we try to initialize DirectX here if DX_WINDOWS is defined 
	
	
#ifdef GLFW_WINDOW
	//opengl also gets initialized
	m_glfwWindow.init();
	m_glfwWindow.create(m_clientOptions.m_screenWidth, m_clientOptions.m_screenHeight);
#endif

	//should initialize the game state game logic and view attached to the game logic 

	//actually i have a bug in the destructor if my texture class right now where i call the stb free method 
	//in the destructor but closing the window and not the program will cause an exception

}