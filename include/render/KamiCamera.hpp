#include "engine/IKamiInputEventListener.hpp"
#include "engine/KamiInputEvent.hpp"
#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
#include <glm/ext/scalar_constants.hpp> // glm::pi
#include <glm/gtc/type_ptr.hpp>

//implements IinputEventListener
class KamiCamera : public IKamiInputEventListener {

public:
	//make these defaults in the default constructor
	//then allow modification of these

	//should i allow some kind of parameters for the constructor ?
	//for now no


	KamiCamera();

	//needs to be the pure virtual implementation
	void notifyInputEvent(KamiInputEvent);
	float m_cameraSpeed; // adjust accordingly
	glm::vec3 m_upReference;
	glm::vec3 m_cameraPos;
	glm::vec3 m_cameraTarget;
	glm::vec3 m_cameraDirection;
	glm::vec3 m_cameraRight;
	glm::vec3 m_cameraUp;
	glm::mat4 m_view;

};