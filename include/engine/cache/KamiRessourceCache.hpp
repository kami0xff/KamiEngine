
//preloading and seting up all the Entitie types;
//This could be in the app layer instead of being a singleton 

//but then the app layer has to be a singleton AppLayer::getInstance().m_ressourceCache.m_entityRessources
//vs KamiRessourceCache::Getinstance().m_entityRessources;

#ifndef KAMI_RESSOURCE_CACHE_H
#define KAMI_RESSOURCE_CACHE_H
#include "nlohmann/json.hpp"
using nlohmann::json;
class KamiRessourceCache 
{
private:
	//static KamiRessourceCache& m_instance;
	KamiRessourceCache();
	KamiRessourceCache& operator=(const KamiRessourceCache&);  // Leave unimplemented
	KamiRessourceCache(const KamiRessourceCache&);

public:
	static KamiRessourceCache& getInstance();

	//what is the difference ?
	//static System& getInstance() {
	//	if (nullptr == obj)
	//		obj = new System();

	//	return obj;
	//}
	
	std::map<std::string, json> m_entityRessources;

	//only app layer should be able to call this function and it should be called only once friend and protected can help mb ?
		//i mean there could be a case when things get fucked and need to reload ?
	void loadEntityRessources();
};
#endif
