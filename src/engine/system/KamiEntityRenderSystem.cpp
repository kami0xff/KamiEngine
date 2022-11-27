#include "engine/system/KamiEntityRenderSystem.hpp"
#include "engine/cache/KamiRessourceCache.hpp"
#include <map>
#include <iostream>
#include <variant>
#include "glad/glad.h"
void KamiEntityRenderSystem::renderEntity(KamiGameEntity& entity)
{
	//if (!(entity.m_components.contains("ShaderComponent") && entity.m_components.contains("OpenGlRenderComponent")))
	//{
	//	std::cout << "RENDER SYSTEM : CANNOT RENDER ENTITY " << entity.m_entityId << " " << entity.m_entityName << "\n";
	//	return;
	//}

	glEnable(GL_DEPTH_TEST);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

	KamiOpenglRenderComponent& openglRenderComponent = std::get<KamiOpenglRenderComponent>(entity.m_components["OpenglRenderComponent"]);
	if (!openglRenderComponent.m_hasOpenglBufferIds)
	{
		glGenBuffers(1, &openglRenderComponent.m_vboId);
		glGenVertexArrays(1, &openglRenderComponent.m_vaoId);
		glGenBuffers(1, &openglRenderComponent.m_eboId);
		openglRenderComponent.m_hasOpenglBufferIds = true;
	}
	glBindVertexArray(openglRenderComponent.m_vaoId);
	glBindBuffer(GL_ARRAY_BUFFER, openglRenderComponent.m_vboId);

	//TODO if EBO enabled bind ebo
	// if(eboRender) 
	// {
	// }
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOID);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(KamiShapePrimitive::g_cube), KamiShapePrimitive::g_cube, GL_STATIC_DRAW);


	//TODO this will copy vertex data possibly not efficient at all will have to see
	CubeVertexDataComponent& cubeDataComponent = std::get<CubeVertexDataComponent>(entity.m_components["CubeVertexComponent"]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cubeDataComponent.m_cubeVertexData), cubeDataComponent.m_cubeVertexData.data(), GL_STATIC_DRAW);


	//TODO do only once per entity 
	for (auto attribPointerInfo : openglRenderComponent.m_vertexAttributes)
	{
		//missing the size of my vertex attribute 
		//this also shoul be done only once 
		glVertexAttribPointer(attribPointerInfo.second.m_index, attribPointerInfo.second.m_size, attribPointerInfo.second.m_type, attribPointerInfo.second.m_normalized, (attribPointerInfo.second.m_stride) * sizeof(float), (void*)(attribPointerInfo.second.m_pointer));
		//sets vertex attribute pointer and information for the current GL_ARRAY_BUFFER
		glEnableVertexAttribArray(attribPointerInfo.second.m_index);

	}

	//unbinding VAO and GL_ARRAY_BUFFER
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//USE THE PROGRAM FROM THE SHADER COMPONENT
	KamiShaderComponent& shaderComponent = std::get<KamiShaderComponent>(entity.m_components["ShaderComponent"]);
	glUseProgram(KamiRessourceCache::getInstance().m_shaderProgramRessources[shaderComponent.m_shaderProgramName]);



	//CREATING THE TEXTURES 
	
	KamiTextureComponent& textureComponent= std::get<KamiTextureComponent>(entity.m_components["TextureComponent"]);
	

	if (!textureComponent.m_hasOpenglTextureBufferId)
	{
		//if multiple textures may need to generate multiple buffers as well ?
		glGenTextures(1, &textureComponent.m_openglTextureBufferId);
		//for now this is here but FUTURE TODO MAKE IT POSSIBLE TO CHANGE WITH PARAMETERS
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		textureComponent.m_hasOpenglTextureBufferId = true;
	}
	//activate texture unit
	glActiveTexture(GL_TEXTURE0 + textureComponent.m_textures[0].m_textureUnit);
	glBindTexture(GL_TEXTURE_2D, textureComponent.m_openglTextureBufferId);

	//i should not have to do this every render either i think 
	
	//this should also be done only once for each texture component of an entity

	if (!textureComponent.m_hasGeneratedTextureAndMipmap)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
			KamiRessourceCache::getInstance().m_textureRessources[textureComponent.m_textures[0].m_textureName].m_width,
			KamiRessourceCache::getInstance().m_textureRessources[textureComponent.m_textures[0].m_textureName].m_height,
			0,
			GL_RGB,
			GL_UNSIGNED_BYTE,
			KamiRessourceCache::getInstance().m_textureRessources[textureComponent.m_textures[0].m_textureName].m_rawTextureData);
		glGenerateMipmap(GL_TEXTURE_2D);
		textureComponent.m_hasGeneratedTextureAndMipmap = true;
		//check if the state of the actual entity is modified because i think its just the copy that 
		//will change perhaps 
	}

	for (auto texture : textureComponent.m_textures)
	{
		glUniform1i(
			glGetUniformLocation(KamiRessourceCache::getInstance().m_shaderProgramRessources[shaderComponent.m_shaderProgramName], texture.m_samplerName.c_str()),

			texture.m_textureUnit
		);
	}

	//TRANSFORM COMPONENT 

	//should it be a vec3 or vec4
	KamiPositionComponent& positionComponent = std::get<KamiPositionComponent>(entity.m_components["PositionComponent"]);

	KamiTransformComponent& transformComponent = std::get<KamiTransformComponent>(entity.m_components["TransformComponent"]);
	if (!transformComponent.m_hasTransformLocations)
	{
		transformComponent.m_modelLocation = glGetUniformLocation(KamiRessourceCache::getInstance().m_shaderProgramRessources[shaderComponent.m_shaderProgramName], "model");

		transformComponent.m_viewLocation = glGetUniformLocation(KamiRessourceCache::getInstance().m_shaderProgramRessources[shaderComponent.m_shaderProgramName], "view");

		transformComponent.m_projectionLocation = glGetUniformLocation(KamiRessourceCache::getInstance().m_shaderProgramRessources[shaderComponent.m_shaderProgramName], "projection");

		transformComponent.m_hasTransformLocations = true;

	}
	glUniformMatrix4fv(transformComponent.m_projectionLocation, 1, GL_FALSE, glm::value_ptr(transformComponent.m_projectionMatrix));


	glBindVertexArray(openglRenderComponent.m_vaoId);

	//TODO i think i need to read the chapter on transofmration again and cameras 
	//???
	//const float radius = 10.0f;
	//float camX = sin(glfwGetTime()) * radius;
	//float camZ = cos(glfwGetTime()) * radius;
	//transformComponent.m_viewMatrix = glm::lookAt(glm::vec3(camX, 0.0, camZ), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));
	//glUniformMatrix4fv(transformComponent.m_viewLocation, 1, GL_FALSE, glm::value_ptr(transformComponent.m_viewMatrix));

	////translate the entity model by position vector 
	//transformComponent.m_modelMatrix = glm::translate(transformComponent.m_modelMatrix, cube);
	//float angle = 20.0f * i;
	//i++;
	//model = glm::rotate(model, glm::radians((float)glfwGetTime() * i), glm::vec3(1.0f, 0.3f, 0.5f));
	//glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));


	//int i = 0;
	//for (auto cube : cubePositions) {
	//	glm::mat4 model = glm::mat4(1.0f);
	//	model = glm::translate(model, cube);
	//	float angle = 20.0f * i;
	//	i++;
	//	model = glm::rotate(model, glm::radians((float)glfwGetTime() * i), glm::vec3(1.0f, 0.3f, 0.5f));
	//	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	//	glDrawArrays(GL_TRIANGLES, 0, 36);


	//TODO
	//In the vertex data i should know how many vertices ther are to drawTODO
	glDrawArrays(GL_TRIANGLES, 0, 36);

}


//read again learnopengl.com
//get cube rendering 
//continue and finish game coding complete
// work on the event system user input with rempap 
// work on UI with dearm imgui that allows for remapping  
// work on fps camera class that moves with mouse movement and has crosshair (Think about multiple possible camera types)
//work on scene data structure space and space partitioning