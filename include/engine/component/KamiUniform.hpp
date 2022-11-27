
//used both for the texture stuff and the normal uniforms in their maps 
//THIS COULD JUST BE STRUCT IN SHADER COMPONENT CLASS JUST LIKE I DID FOR THE TEXTURE COMPONENT
#ifndef KAMI_UNIFORM_H
#define KAMI_UNIFORM_H
#include <string>
class KamiUniform 
{
public:
	std::string m_uniformName;
	std::string m_uniformType;
	KamiUniform(std::string, std::string);
};
#endif