
#ifndef KAMI_GAME_ENTITY_H
#define KAMI_GAME_ENTITY_H
#include "engine/entity/KamiEntityComponent.hpp"
#include <glm/glm.hpp>
#include <map>
#include <variant>
class KamiGameEntity {
public:

	unsigned int m_entityId;
	std::string m_entityName;
	std::map<std::string, KamiEntityComponent> m_components;
	KamiGameEntity();
	KamiGameEntity(unsigned int, std::string);
	void addComponent(std::string, KamiEntityComponent);

};
#endif
