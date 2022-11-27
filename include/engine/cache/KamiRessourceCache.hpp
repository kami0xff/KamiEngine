

#ifndef KAMI_RESSOURCE_CACHE_H
#define KAMI_RESSOURCE_CACHE_H
#include "nlohmann/json.hpp"
#include "engine/cache/KamiTexture.hpp"
using nlohmann::json;
class KamiRessourceCache 
{
private:
	KamiRessourceCache();
	KamiRessourceCache& operator=(const KamiRessourceCache&);
	KamiRessourceCache(const KamiRessourceCache&);

public:
	static KamiRessourceCache& getInstance();

	std::map<std::string, json> m_entityRessources;
	//ok this is cool but what about the shader programs i need to create ??
	//TODO MAKE SURE TO CREATE SHADER PROGRAMS ONCE AT LOAD TIME AND NOT ONCE PER ENTITY
	std::map<std::string, std::string> m_vertexShaderRessources;
	std::map<std::string, std::string> m_fragmentShaderRessources;

	std::map<std::string, unsigned int> m_shaderProgramRessources;

	//TODO add loading the texture to the ressource cache. 
	std::map<std::string, KamiTexture> m_textureRessources;

	void loadEntityRessources();
	void loadVertexShaderRessources();
	void loadFragmentShaderRessources();
	void createShaderPrograms();
	void loadTextures();
};	
#endif
