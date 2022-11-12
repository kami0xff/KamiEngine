
#ifndef KAMI_GAME_ENTITY_FACTORY_H
#define KAMI_GAME_ENTITY_FACTORY_H
#include "engine/entity/KamiGameEntity.hpp"
#include <string>
class KamiGameEntityFactory 
{
private:
	unsigned int m_entityId = 0;
public:
	KamiGameEntityFactory();
	KamiGameEntity createEntity(std::string);
};
#endif