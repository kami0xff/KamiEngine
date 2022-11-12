
#ifndef KAMI_GAME_ENTITY_H
#define KAMI_GAME_ENTITY_H
#include <glm/glm.hpp>
#include <map>
#include <variant>
#include "engine/entity/KamiEntityComponent.hpp"
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

//XML example of entity defintion 
//<Actor>
	//<CubePhysicsComponent>
		//<InitialTransform>
			//<Position x = “0” y = “5” z = “0” / >
			//<Orientation degrees = “ - 90” / >
		//< / InitialTransform>
		//<Shape>
			//<Dimensions x = “1” y = “1” z = “1” / >
		//< / Shape>
		//<Density>castIron< / Density>
		//<PhysicsMaterial>Normal< / PhysicsMaterial>
	//< / CubePhysicsComponent>
	//<TeapotRenderComponent>
		//<Color r = “0” g = “0” b = “1.0” a = “1.0” / >
	//< / TeapotRenderComponent>
//< / Actor>