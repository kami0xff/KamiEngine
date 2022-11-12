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


//PUBLIC INTERFACE----------

void KamiTextureComponent::createTexture()
{
	//#ifdef KAMI_GLAD_LOADED

	//stores the handle to the texture in m_id so yes this should be in the component code then
	glGenTextures(1, &m_id);
	//setting the texture wrapping and filtering options here for now 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//#else
}

void KamiTextureComponent::bindTexture(int textureUnit)
{
	glActiveTexture(GL_TEXTURE0 + textureUnit);//activate texture unit
	glBindTexture(GL_TEXTURE_2D, m_id);
}

void KamiTextureComponent::generateTexture()
{
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGB, GL_UNSIGNED_BYTE, m_data);
	glGenerateMipmap(GL_TEXTURE_2D);
}