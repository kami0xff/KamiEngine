
#ifndef KAMI_OPENGL_RENDER_COMPONENT_H
#define KAMI_OPENGL_RENDER_COMPONENT_H
#include "engine/component/KamiVertexAttribute.hpp"
#include "nlohmann/json.hpp"
#include "glad/glad.h" 
#include <GLFW/glfw3.h>
#include <map>
#include <string>
using nlohmann::json;

class KamiOpenglRenderComponent 
{
public:
	unsigned int m_componentId;
	std::string m_componentName;
	unsigned int m_vboId;
	unsigned int m_vaoId;
	unsigned int m_eboId;

	//rendering once will set those fields so if it has been done 
	//this should be true and if the entity is rendered again then it should not 
	//regenerate stuff 
	//still missing the case when an entity is not rendered anymore and freeing ressources
	//but i think that will come with the scene structure 
	bool m_hasOpenglBufferIds;

	std::map<std::string, KamiVertexAttribute> m_vertexAttributes;

	KamiOpenglRenderComponent();
	KamiOpenglRenderComponent(unsigned int, std::string);

};
#endif