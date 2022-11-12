#include "engine/entity/KamiGameEntity.hpp"
#include <string>

KamiGameEntity::KamiGameEntity() 
{
	m_entityId = 0;
	m_entityName = "default";
}

KamiGameEntity::KamiGameEntity(unsigned int entityId, std::string entityName) 
{
	m_entityId = entityId;
	m_entityName = entityName;
}

void KamiGameEntity::addComponent(std::string componentName,KamiEntityComponent component) 
{
	m_components[componentName] = component;
}
