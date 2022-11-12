#include "engine/applayer/KamiTextRessources.hpp"
KamiTextRessources& KamiTextRessources::getInstance()
{
	static KamiTextRessources instance;
	return instance;
}