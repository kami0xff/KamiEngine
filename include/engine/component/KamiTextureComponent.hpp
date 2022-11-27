#ifndef KAMI_TEXTURE_COMPONENT_H
#define KAMI_TEXTURE_COMPONENT_H
#include "engine/cache/KamiTexture.hpp"
#include <string>
#include <map>
#include <vector>
struct TextureInfo {
	unsigned int m_textureUnit;
	std::string m_textureName;
	std::string m_samplerName;
};

class KamiTextureComponent
{
public :
	unsigned int m_componentId;
	std::string m_componentName;

	bool m_hasOpenglTextureBufferId = false;
	bool m_hasGeneratedTextureAndMipmap = false;
	unsigned int m_openglTextureBufferId;

	std::vector<TextureInfo> m_textures;


	KamiTextureComponent();
	KamiTextureComponent(unsigned int, std::string);
};

#endif