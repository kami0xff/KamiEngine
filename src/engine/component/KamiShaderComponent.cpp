
#include "engine/component/KamiShaderComponent.hpp"
#include "engine/cache/KamiRessourceCache.hpp"
#include "glad/glad.h"
#include <iostream>
KamiShaderComponent::KamiShaderComponent()
{
	m_componentId = 0;
	m_componentName = "default";
}

//todo set the shadercomponent based on the shaderProgramName that was found in the entity json
//by looking in the ressource cache if it could be found if not found need to output and log error
KamiShaderComponent::KamiShaderComponent(unsigned int componentId, std::string componentName, unsigned int shaderProgramId, std::string shaderProgramName)
{
	m_componentId = componentId;
	m_componentName = componentName;
	m_shaderProgramId = shaderProgramId;
	m_shaderProgramName = shaderProgramName;
}