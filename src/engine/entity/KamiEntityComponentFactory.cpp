
#include "engine/entity/KamiEntityComponentFactory.hpp"
#include "engine/entity/KamiEntityComponent.hpp"
#include "engine/component/CubeVertexDataComponent.hpp"
#include "engine/component/KamiPositionComponent.hpp"
#include "engine/component/KamiTextureComponent.hpp"
#include "engine/component/KamiTransformComponent.hpp"
#include <variant>
#include <string>
#include <iostream>
using nlohmann::json;

//using EntityComponent = std::variant<...>

KamiEntityComponent KamiEntityComponentFactory::createComponent(json componentData)
{
	std::string componentName = componentData["componentName"].get<std::string>();

	if (componentName == "CubeVertexDataComponent") {
		m_componentId++;
		return createCubeVertexDataComponent(componentData);
	}
	else if(componentName == "PositionComponent")
	{
		m_componentId++;
		return createPositionComponent(componentData);
	}
	else if(componentName == "TransformComponent")
	{
		m_componentId++;
		return createTransformComponent(componentData);
	}
	else {
		std::cout << "CREATE COMPONENT : CANNOT FIND COMPONENT NAME\n";
	}

}


KamiEntityComponent KamiEntityComponentFactory::createPositionComponent(json componentData)
{
	KamiPositionComponent component{ m_componentId, componentData["componentName"].get<std::string>() };
	return KamiEntityComponent{ component };
}

//KamiEntityComponent KamiEntityComponentFactory::createTextureComponent(json componentData)
//{
//
//}

KamiEntityComponent KamiEntityComponentFactory::createTransformComponent(json componentData)
{
	KamiTransformComponent component{ m_componentId,componentData["componentName"].get<std::string>() };
	return KamiEntityComponent{ component };
}



KamiEntityComponent KamiEntityComponentFactory::createCubeVertexDataComponent(json componentData)
{
	CubeVertexDataComponent component{ m_componentId, componentData["componentName"].get<std::string>()};
	return KamiEntityComponent{ component };
}

