
#ifndef KAMI_VERTEX_ATTRIBUTE_H
#define KAMI_VERTEX_ATTRIBUTE_H
#include <string>
#include "glad/glad.h"
class KamiVertexAttribute
{

public:
	std::string m_attributeName;
	unsigned int m_index;
	unsigned int m_size;
	int m_type;
	unsigned int m_normalized;
	unsigned int m_stride;
	unsigned int m_pointer;
	//does nothing
	KamiVertexAttribute();
	KamiVertexAttribute(std::string, unsigned int, unsigned int, int, unsigned int, unsigned int, unsigned int);
};
#endif


//opengl integers that represent types 
//#define GL_FALSE 0
//#define GL_TRUE 1
//#define GL_BYTE 0x1400
//#define GL_UNSIGNED_BYTE 0x1401
//#define GL_SHORT 0x1402
//#define GL_UNSIGNED_SHORT 0x1403
//#define GL_INT 0x1404
//#define GL_UNSIGNED_INT 0x1405
//#define GL_FLOAT 0x1406