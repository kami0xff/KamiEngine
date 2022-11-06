#include "engine/appLayer/KamiClientOptions.hpp"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

void KamiClientOptions::readClientOptionsJson() {
	//
	using nlohmann::json;
	std::ifstream f("..\\..\\..\\..\\kami\\config\\options.json");
	if (!f)
	{
		std::cout << "could not open the configuration file";
	}
	json data = json::parse(f);
	m_screenHeight = data["screenHeight"];
	m_screenWidth = data["screenWidth"];
	m_mouseSens = data["mouseSens"];
}


void KamiClientOptions::saveClientOptionsJson() {
	using nlohmann::json;
	json options;
	options["screenHeight"] = m_screenHeight;
	options["screenWidth"] = m_screenHeight;
	options["mouseSens"] = m_mouseSens;

	std::ofstream myfile;
	myfile.open("..\\..\\..\\..\\kami\\config\\options.json");
	myfile << std::setw(4) << options << std::endl;
	myfile.close();
}