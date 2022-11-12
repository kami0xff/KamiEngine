#include "engine/entity/KamiEntityComponentFactory.hpp"
#include "engine/cache/KamiRessourceCache.hpp"
#include "engine/entity/KamiGameEntityFactory.hpp"
#include "engine/entity/KamiEntityManager.hpp"
#include "nlohmann/json.hpp"
#include <iostream>
using nlohmann::json;

//CONSTRUCTOR----------
KamiGameEntityFactory::KamiGameEntityFactory() 
{
	m_entityId = 0;
}

KamiGameEntity KamiGameEntityFactory::createEntity(std::string entityName)
{
	
	//entityNames act as types
	if (KamiRessourceCache::getInstance().m_entityRessources.find(entityName) == KamiRessourceCache::getInstance().m_entityRessources.end()) 
	{
		std::cout << "ERROR could not find the entity with the name : " << entityName << "\n";
	}
	json entityData = KamiRessourceCache::getInstance().m_entityRessources[entityName];


	KamiGameEntity newGameEntity{m_entityId, entityName};
	
	KamiEntityComponentFactory componentFactory{};


	for (auto componentData : entityData["components"]) {
		std::cout << componentData << "/n";
		KamiEntityComponent newComponent = componentFactory.createComponent(componentData);
		newGameEntity.addComponent(componentData["componentName"].get<std::string>(), newComponent);
	}

	KamiEntityManager::getInstance().addEntity(newGameEntity);
	m_entityId++;

	return newGameEntity;
}