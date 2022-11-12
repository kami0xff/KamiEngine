
#ifndef KAMI_POSITION_COMPONENT_H
#define KAMI_POSITION_COMPONENT_H
#include "glm/glm.hpp"
#include <string>
class KamiPositionComponent
{
public:
	unsigned int m_componentId;
	std::string m_componentName;
	glm::vec4 m_position{0};
	KamiPositionComponent();
	KamiPositionComponent(unsigned int, std::string);
};
#endif