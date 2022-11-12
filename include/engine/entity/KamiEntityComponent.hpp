
#ifndef KAMI_ENTITY_COMPONENT_H
#define KAMI_ENTITY_COMPONENT_H
#include "engine/component/CubeVertexDataComponent.hpp"
#include "engine/component/KamiPositionComponent.hpp"
#include "engine/component/KamiTransformComponent.hpp"
#include "engine/component/KamiTextureComponent.hpp"
#include <variant>
using KamiEntityComponent = std::variant<
	CubeVertexDataComponent,
	KamiPositionComponent,
	KamiTextureComponent,
	KamiTransformComponent>;
#endif