#include "engine/component/KamiPositionComponent.hpp"
#include "glm/glm.hpp"

KamiPositionComponent::KamiPositionComponent() {
	m_componentId = 0;
	m_componentName = "default";
}

KamiPositionComponent::KamiPositionComponent(unsigned int componentId, std::string componentName) {
	m_componentId = componentId;
	m_componentName = componentName;
}