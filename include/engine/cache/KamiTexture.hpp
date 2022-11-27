
#ifndef KAMI_TEXTURE_H
#define KAMI_TEXTURE_H
class KamiTexture {
public:
	unsigned char* m_rawTextureData;
	int m_width, m_height, m_nrChannels;
	int m_textureUnit;
};
#endif