
#include "engine/component/KamiVertexAttribute.hpp"

KamiVertexAttribute::KamiVertexAttribute() 
{

	m_attributeName = "default";
	m_index = 0;
	m_size = 0;
	m_type = 0;
	m_normalized = 0;
	m_stride = 0;
	m_pointer = 0;

}

KamiVertexAttribute::KamiVertexAttribute(std::string attributeName, unsigned int size, unsigned int index, int glType, unsigned int glNormalize, unsigned int stride, unsigned int pointer)
{
	m_attributeName = attributeName;
	m_index = index;
	m_size = size;
	m_type = glType; //we will see if opengl can convert it to its own types
	m_normalized = glNormalize;
	m_stride = stride;
	m_pointer = pointer;
}

