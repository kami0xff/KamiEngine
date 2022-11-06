#pragma once



#include <glad/glad.h> 
#include <GLFW/glfw3.h>

#include "network/KamiNet.hpp"
#include "render/KamiRender.hpp"
#include "render/KamiShader.hpp"
#include "render/KamiShapePrimitive.hpp"
#include "render/KamiTexture.hpp"
#include "platform/KamiGlfwWindow.hpp"

#include <glm/glm.hpp>
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
#include <glm/ext/scalar_constants.hpp> // glm::pi
#include <glm/gtc/type_ptr.hpp>

#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/ranges.h>

#include <nlohmann/json.hpp>

//boost was weird

class KamiEngine {

public:
	void init();
};