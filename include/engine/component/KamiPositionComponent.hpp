
#ifndef KAMI_POSITION_COMPONENT_H
#define KAMI_POSITION_COMPONENT_H
#include "glm/glm.hpp"
#include <string>
#include <vector>
class KamiPositionComponent
{
public:
	unsigned int m_componentId;
	std::string m_componentName;
	glm::vec3 m_position{0};
	KamiPositionComponent();
	//taking a vector of int but glm::vec4 for the member
	KamiPositionComponent(unsigned int, std::string, std::vector<int>);
};
#endif