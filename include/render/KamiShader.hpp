
#include <glad/glad.h> 
#include <map>
#include <string>
#include <fstream>
#include <sstream>

class KamiShader {

public:
	//glsl shader preprocessor for includes in glsl files if i ever need this
	//utilities for uniforms

	//void createVertexShader(std::string vertexPath);
	//void createFragmentShader(std::string fragmentPath);
	void createShaderProgram(std::string name,std::string vertexPath, std::string fragmentPath);
	
	//void useShaderProgram(std::string name);

	//void printShaderProgramID();
	//void printVertexShaderID();
	//void printfragmentShaderID();

	
	//void deleteVertexShader(std::string vertexPath);
	//void deleteFragmentShader(std::string fragmentPath);
	//delete program
	
	//delete everything
	//void purgeAllShaders();

	//

	//store vertex and fragment shader code in map once loaded for reuse
	std::map<std::string, std::string> m_vertexShaderCodeMap;
	std::map<std::string, std::string> m_fragmentShaderCodeMap;
	
	//store the OpenGl Ids
	std::map<std::string, unsigned int> m_vertexShaderMap;
	std::map<std::string, unsigned int> m_fragmentShaderMap;
	std::map<std::string, unsigned int> m_shaderProgramMap;
};