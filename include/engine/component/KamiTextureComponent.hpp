#ifndef KAMI_TEXTURE_COMPONENT_H
#define KAMI_TEXTURE_COMPONENT_H
#include <string>
class KamiTextureComponent
{
public :
	unsigned int m_componentId;
	std::string m_componentName;
	unsigned char* m_data;
	unsigned int m_id;
	int m_width, m_height, m_nrChannels;


	//some kind of error checking if this function succeeded ??? std::optional ?
	void readTexture(const char*); 
	//should be done in the ressource cache 
	//if not in the ressource cache then should read it here 
	//TODO read all textures in the ressource cache

	
	void createTexture();
	void bindTexture(int);
	void generateTexture();

	KamiTextureComponent();
	KamiTextureComponent(unsigned int, std::string);


	//~KamiTexture(); maybe a destructor that clears the loaded texture data TODO ?
};

#endif