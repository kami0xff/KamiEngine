#include "engine/entity/KamiEntityManager.hpp"

//CONSTRUCTOR----------
//
KamiEntityManager::KamiEntityManager() 
{}

KamiEntityManager& KamiEntityManager::getInstance()
{
	static KamiEntityManager instance;
	return instance;
}

void KamiEntityManager::addEntity(KamiGameEntity entity)
{
	m_entities[entity.m_entityId] = entity;
}
void KamiEntityManager::removeEntity(unsigned int entityId)
{
	//yeah for now i don't know how to do this becaues most likely i will remove things in the middle of the map so 
	//its not like a linked list where i can easily remove from the middle is it ?

	//...

}