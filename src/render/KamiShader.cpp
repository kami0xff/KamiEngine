#include <render/KamiShader.hpp>
#include <iostream>
#include <fmt/core.h>

//this function does more than just create a shader program it reads files stores them 
//TODO split it 

//CTRE LIBRARY FOR REGEX IN CPP
void KamiShader::createShaderProgram(std::string name, std::string vertexPath, std::string fragmentPath) 
{
	std::string vertexCode;
	std::string fragmentCode;
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;

	//ensures exceptions
	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit); //bitwise or to combine the two bitmask types
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try 
	{
		fmt::print("vertex : {}\n", vertexPath);
		fmt::print("fragment : {}\n", fragmentPath);
		vShaderFile.open(vertexPath);
		fShaderFile.open(fragmentPath);

		std::stringstream vShaderStream, fShaderStream;
		// read file's buffer contents into streams
		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();
		// close file handlers
		vShaderFile.close();
		fShaderFile.close();
		// convert stream into string
		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();

		//store file contents for reuse
		m_vertexShaderCodeMap[vertexPath] = vertexCode;
		m_fragmentShaderCodeMap[fragmentPath] = fragmentCode;

		unsigned int vertexShaderId, fragmentShaderId, shaderProgramId;

		//can you convert std::string to const char*
		//strings and streams is one area where i need to improve for sure in c++ c
		const char* vcode = vertexCode.c_str();
		const char* fcode = fragmentCode.c_str();

		int success;
		char infoLog[512];

		//then i also need to pass in the path if i want to store it in the map
		//compileVertexShader(const char* vcode)
		vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShaderId, 1, &vcode, NULL);
		glCompileShader(vertexShaderId);
		//check compilation result from opengl
		glGetShaderiv(vertexShaderId, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertexShaderId, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		};
		m_vertexShaderMap[vertexPath] = vertexShaderId;

		//fragment compile
		//compileFragmentShader(const char* fcode)
		fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShaderId, 1, &fcode, NULL);
		glCompileShader(fragmentShaderId);
		//check compilation result 
		m_fragmentShaderMap[fragmentPath] = fragmentShaderId;
		glGetShaderiv(fragmentShaderId, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragmentShaderId, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		};
		m_fragmentShaderMap[fragmentPath] = fragmentShaderId;


		//would need the name the vertex shader and fragment ids 
		//linkProgram()
		shaderProgramId = glCreateProgram();
		glAttachShader(shaderProgramId, vertexShaderId);
		glAttachShader(shaderProgramId, fragmentShaderId);
		glLinkProgram(shaderProgramId);
		//check result ?
		glGetProgramiv(shaderProgramId, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shaderProgramId, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		}
		m_shaderProgramMap[name] = shaderProgramId;
	}
	
	catch (std::ifstream::failure e) 
	{
		//should log the error 
		std::cerr << "Shader Program Creation failed " << e.what() << "\n";
	}

}

