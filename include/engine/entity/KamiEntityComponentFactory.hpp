
#ifndef KAMI_ENTITY_COMPONENT_FACTORY_H
#define KAMI_ENTITY_COMPONENT_FACTORY_H
#include "engine/entity/KamiEntityComponent.hpp"
#include "nlohmann/json.hpp"
using nlohmann::json;
class KamiEntityComponentFactory
{
public:
	unsigned int m_componentId;
	KamiEntityComponent createComponent(json);

private:
	KamiEntityComponent createPositionComponent(json);
	//KamiEntityComponent createTextureComponent(json);
	KamiEntityComponent createTransformComponent(json);
	KamiEntityComponent createCubeVertexDataComponent(json);
};
#endif