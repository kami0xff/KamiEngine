#include "engine/component/KamiPositionComponent.hpp"
#include "glm/glm.hpp"
KamiPositionComponent::KamiPositionComponent() {
	m_componentId = 0;
	m_componentName = "default";
}

KamiPositionComponent::KamiPositionComponent(unsigned int componentId, std::string componentName, std::vector<int> positions) {
	m_componentId = componentId;
	m_componentName = componentName;
	m_position = glm::vec3{ positions[0],positions[1],positions[2]};
}