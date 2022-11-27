
#include "engine/component/KamiOpenglRenderComponent.hpp"
KamiOpenglRenderComponent::KamiOpenglRenderComponent() {
	m_componentId = 0;
	m_componentName = "default";
}

KamiOpenglRenderComponent::KamiOpenglRenderComponent(unsigned int componentId, std::string componentName) {
	m_componentId = componentId;
	m_componentName = componentName;
}
