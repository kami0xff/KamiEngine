#ifndef CUBE_VERTEX_DATA_COMPONENT_H
#define CUBE_VERTEX_DATA_COMPONENT_H
#include <string>
#include <vector>
class CubeVertexDataComponent
{
public:
	unsigned int m_componentId;
	std::string m_componentName;

	std::vector<float> m_cubeVertexData;
	CubeVertexDataComponent();
	CubeVertexDataComponent(unsigned int, std::string);
};
#endif