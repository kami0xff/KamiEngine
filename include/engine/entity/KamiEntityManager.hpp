
#ifndef KAMI_ENTITY_MANAGER_H
#define KAMI_ENTITY_MANAGER_H
#include "engine/entity/KamiGameEntity.hpp"
#include <map>
class KamiEntityManager {
private:
	//TODO make singleton
	KamiEntityManager();
	KamiEntityManager& operator=(const KamiEntityManager&);  // Leave unimplemented
	KamiEntityManager(const KamiEntityManager&);

public:
	static KamiEntityManager& getInstance();
	void addEntity(KamiGameEntity);
	void removeEntity(unsigned int);
	std::map<unsigned int, KamiGameEntity> m_entities;
};
#endif