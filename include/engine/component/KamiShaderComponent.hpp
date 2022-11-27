#ifndef KAMI_SHADER_COMPONENT_H
#define KAMI_SHADER_COMPONENT_H
#include "engine/component/KamiUniform.hpp"
#include <string>
#include <map>
class KamiShaderComponent 
{
public:
	unsigned int m_componentId;
	std::string m_componentName;
	unsigned int m_shaderProgramId;
	std::string m_shaderProgramName;

	std::map<std::string, KamiUniform> m_uniforms;

	KamiShaderComponent();
	//CONSIDER this constructor will have to look in ressource cache and might not find what it needs if there is a mistake
		//need to cout error
		//nevermind the check should be done in the factory function in componentFactory
	KamiShaderComponent(unsigned int, std::string, unsigned int shaderProgramId, std::string shaderProgramName );
};
#endif