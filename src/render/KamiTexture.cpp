#define STB_IMAGE_IMPLEMENTATION
#include "render/KamiTexture.hpp"
#include "fmt/core.h"
#include "stb_image.h"
#include "GLAD/glad.h"


//free the image data once we are done with this object
KamiTexture::~KamiTexture()
{
	stbi_image_free(m_data);
}

void KamiTexture::readContainerTexture()
{

	//where is this data ?? data should be pointing to some temporary object here ??
	//so im not sure i might be returning a pointer that points to nothing after this function its a bit strange 
	m_data = stbi_load("C:\\Dev\\C++_CMAKE_Learning\\engine\\texture\\container.jpg", &m_width, &m_height, &m_nrChannels, 0);

	if (!m_data)
	{
		fmt::print("Failed to load texture\n");
		//should log to file as well if some flag enabled this kind of things 
		//like #ifdef KAMI_LOG log these outputs to a file 
	}
	//maybe i should have a default texture that shows when something is bugged like something that is always loaded at the start 
	//like the cs purple and black squares 
}

void KamiTexture::createTexture()
{
	//opengl functions should always be called in a context where glad is initialized
	glGenTextures(1, &m_id);

	//setting the texture wrapping and filtering options here for now 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void KamiTexture::bindTexture()
{
	glBindTexture(GL_TEXTURE_2D, m_id);
}

void KamiTexture::generateTexture()
{
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGB, GL_UNSIGNED_BYTE, m_data);
	glGenerateMipmap(GL_TEXTURE_2D);
}