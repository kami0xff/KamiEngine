#ifndef KAMI_TRANSFORM_COMPONENT_H
#define KAMI_TRANSFORM_COMPONENT_H
#include <string>
#include "glm/glm.hpp"
class KamiTransformComponent
{
public :
	unsigned int m_componentId;
	std::string m_componentName;
	glm::mat4 model = glm::mat4(1.0f); //identity matrix by default and we can just modify model matrix ?
	
	KamiTransformComponent();
	KamiTransformComponent(unsigned int, std::string);

};
#endif