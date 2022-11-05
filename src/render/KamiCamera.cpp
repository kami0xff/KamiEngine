#include "render/KamiCamera.hpp"
#include <iostream> //change to fmt 


//make the camera register as an inputevent listener by default
KamiCamera::KamiCamera() 
{
	m_upReference = glm::vec3(0.0f, 0.1f, 0.0f);
	m_cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
	m_cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
	m_cameraDirection = glm::normalize(m_cameraPos - m_cameraTarget);
	m_cameraRight = glm::normalize(glm::cross(m_upReference, m_cameraDirection));
	m_cameraUp = glm::cross(m_cameraDirection, m_cameraRight);
	m_view = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f),
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f));

	m_cameraSpeed = 0.5;
	m_cameraFront = glm::vec3(0);
}

//void KamiCamera::notifyInputEvent(KamiInputEvent inputEvent) 
//{
//
//	switch (inputEvent) 
//	{
//	case MOVEMENT_FORWARD:
//		std::cout << "moving camera forward \n";
//		m_cameraPos += m_cameraSpeed * m_cameraFront;
//		break;
//	case MOVEMENT_BACKWARD:
//		m_cameraPos -= m_cameraSpeed * m_cameraFront;
//		break;
//	case MOVEMENT_LEFT:
//		m_cameraPos -= glm::normalize(glm::cross(m_cameraFront, m_cameraUp)) * m_cameraSpeed;
//		break;
//	case MOVEMENT_RIGHT:
//		m_cameraPos += glm::normalize(glm::cross(m_cameraFront, m_cameraUp)) * m_cameraSpeed;
//		break;
//	}
//
//}