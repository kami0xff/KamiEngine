
#include "nlohmann/json.hpp"

class KamiClientOptions {
public:
	unsigned int m_screenHeight;
	unsigned int m_screenWidth;
	double m_mouseSens;

	void readClientOptionsJson();
	void saveClientOptionsJson();

};