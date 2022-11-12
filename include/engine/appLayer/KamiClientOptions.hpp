#ifndef KAMI_CLIENT_OPTIONS_H
#define KAMI_CLIENT_OPTIONS_H
#include "nlohmann/json.hpp"
class KamiClientOptions 
{
private:
	KamiClientOptions() {};
	KamiClientOptions& operator=(const KamiClientOptions&);  // Leave unimplemented
	KamiClientOptions(const KamiClientOptions&);

public:
	static KamiClientOptions& getInstance();

	//TODO what is best practise
	//should i set them like this for my defaults or in the default constructor ??
	unsigned int m_screenHeight;
	unsigned int m_screenWidth;
	double m_mouseSens;

	void readClientOptionsJson();
	void saveClientOptionsJson();
};
#endif