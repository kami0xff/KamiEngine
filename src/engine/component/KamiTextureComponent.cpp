#include "engine/component/KamiTextureComponent.hpp"
#include "fmt/core.h"
#include "GLAD/glad.h"

//CONSTRUCTOS----------
KamiTextureComponent::KamiTextureComponent() {
	m_componentId = 0;
	m_componentName = "default";
}

KamiTextureComponent::KamiTextureComponent(unsigned int componentId, std::string componentName) {
	m_componentId = componentId;
	m_componentName = componentName;
}
