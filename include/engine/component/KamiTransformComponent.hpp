#ifndef KAMI_TRANSFORM_COMPONENT_H
#define KAMI_TRANSFORM_COMPONENT_H
#include <string>
#include "glm/glm.hpp"
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
#include <glm/ext/scalar_constants.hpp> // glm::pi
#include <glm/gtc/type_ptr.hpp>
class KamiTransformComponent
{
public :
	unsigned int m_componentId;
	std::string m_componentName;


	//how to set defaults 
	glm::mat4 m_modelMatrix = glm::mat4(1.0f);

	//view matrix
	glm::mat4 m_viewMatrix = glm::mat4(1.0f);

	//projection matrix TODO how to set the defaults for this ???
	glm::mat4 m_projectionMatrix = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
	

	//change the name to has been rendered once or idk TODO
	bool m_hasTransformLocations = false;



	//set when rendered the first time
	unsigned int m_modelLocation; 
	unsigned int m_viewLocation;
	unsigned int m_projectionLocation;

	KamiTransformComponent();
	KamiTransformComponent(unsigned int, std::string);


};
#endif