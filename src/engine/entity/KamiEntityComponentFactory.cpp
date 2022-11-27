
#include "engine/cache/KamiRessourceCache.hpp"
#include "engine/entity/KamiEntityComponentFactory.hpp"
#include "engine/entity/KamiEntityComponent.hpp"
#include "engine/component/CubeVertexDataComponent.hpp"
#include "engine/component/KamiPositionComponent.hpp"
#include "engine/component/KamiTextureComponent.hpp"
#include "engine/component/KamiTransformComponent.hpp"
#include "engine/component/KamiShaderComponent.hpp"
#include "engine/component/KamiOpenglRenderComponent.hpp"
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
	else if (componentName == "ShaderComponent") 
	{
		m_componentId++;
		return createShaderComponent(componentData);
	}	
	else if (componentName == "OpenglRenderComponent") 
	{
		m_componentId++;
		return createOpenglRenderComponent(componentData);
	}	
	else if (componentName == "TextureComponent") 
	{
		m_componentId++;
		return createTextureComponent(componentData);
	}
	else {
		std::cout << "CREATE COMPONENT : CANNOT FIND COMPONENT NAME\n";
	}

}


KamiEntityComponent KamiEntityComponentFactory::createPositionComponent(json componentData)
{
	std::vector<int> positionVector;
	for (auto position :  componentData["position"]) {
		positionVector.push_back(position.get<int>());
	}

	KamiPositionComponent component{ m_componentId, componentData["componentName"].get<std::string>(), positionVector};
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

KamiEntityComponent KamiEntityComponentFactory::createShaderComponent(json componentData) 
{
	//check if the shader program name in the json exists in the ressource cache 
	std::string shaderProgramName = componentData["shaderProgramName"].get<std::string>();
	if (KamiRessourceCache::getInstance().m_shaderProgramRessources.find(shaderProgramName) == KamiRessourceCache::getInstance().m_shaderProgramRessources.end()) 
	{
		std::cout << "SHADER COMPONENT : COULD NOT FIND shaderProgramName In Ressourcd cache : " << shaderProgramName << "\n";
		//CONSIDER should i renturn empty stuff or the default kamiShaderComponent if something fails i think its better to return default??
		return KamiEntityComponent{};
	}

	KamiShaderComponent component{ m_componentId, componentData["componentName"].get<std::string>(),KamiRessourceCache::getInstance().m_shaderProgramRessources[shaderProgramName] ,shaderProgramName};

	return KamiEntityComponent{ component };
}


KamiEntityComponent KamiEntityComponentFactory::createOpenglRenderComponent(json componentData)
{
	KamiOpenglRenderComponent component{m_componentId,componentData["componentName"].get<std::string>()};
	for (auto vertexAttributeData : componentData["vertexAttributes"])
	{
		KamiVertexAttribute vertexAttribute{
			vertexAttributeData["attributeName"].get<std::string>(),
			vertexAttributeData["index"].get<unsigned int>(),
			vertexAttributeData["size"].get<unsigned int>(),
			vertexAttributeData["type"].get<int>(),
			vertexAttributeData["normalized"].get<unsigned int>(),
			vertexAttributeData["stride"].get<unsigned int>(),
			vertexAttributeData["pointer"].get<unsigned int>(),
		};
		component.m_vertexAttributes[vertexAttributeData["attributeName"].get<std::string>()] = vertexAttribute;
	}

	return KamiEntityComponent{ component };
}


KamiEntityComponent KamiEntityComponentFactory::createTextureComponent(json componentData)
{
	//and maybe mapped with their texture units ? like std::map<name, texture unit>
	KamiTextureComponent component{ m_componentId,componentData["componentName"].get<std::string>() };
	for (auto textureData : componentData["textures"]) {
		component.m_textures.push_back(
			TextureInfo{
				textureData["textureUnit"].get<unsigned int>(),
				textureData["textureName"].get<std::string>(),
				textureData["textureSampler"].get<std::string>()
			}
		);
	}
	return KamiEntityComponent{ component };
}