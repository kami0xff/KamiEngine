
#define STB_IMAGE_IMPLEMENTATION
#include "engine/cache/KamiRessourceCache.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <fstream>
#include "stb_image.h"
#include "glad/glad.h"
#include "nlohmann/json.hpp"


//CONSTRUCTOR----------
KamiRessourceCache::KamiRessourceCache()
{
}
KamiRessourceCache& KamiRessourceCache::getInstance()
{
	static KamiRessourceCache theInstance;
	return theInstance;
}
void KamiRessourceCache::loadEntityRessources()
{
	using nlohmann::json;
	using std::filesystem::directory_iterator;
	std::string path = "..\\..\\..\\..\\kami\\assets\\entity";
	//would be cool to have the entity name to save to the map 
	for (const auto& file : directory_iterator(path))
	{
		std::fstream f(file.path());
		if (!f)
		{
			std::cout << "could not open the ressource file";
		}

		std::cout << "READING THIS : " << file.path().string();

		json data = json::parse(f);

		m_entityRessources[data["entityName"]] = data;
	}
}

void KamiRessourceCache::loadVertexShaderRessources()
{
	using std::filesystem::directory_iterator;
	std::string path = "..\\..\\..\\..\\kami\\assets\\shader\\vertex";

	for (const auto& file : directory_iterator(path))
	{

		std::ifstream vShaderFile(file.path());
		if (!vShaderFile)
		{
			std::cout << "FAILED TO READ VERTEX SHADER FILE\n";
		}
		std::stringstream vShaderStream;
		vShaderStream << vShaderFile.rdbuf();
		vShaderFile.close();
		std::string vertexCode = vShaderStream.str();

		auto tmp = file.path();
		std::cout << "LOADING VERTEX SHADER FILE : " << tmp.filename().string() << "\n";
		m_vertexShaderRessources[tmp.filename().string()] = vertexCode;
	}
}


void KamiRessourceCache::loadFragmentShaderRessources()
{
	using std::filesystem::directory_iterator;
	std::string path = "..\\..\\..\\..\\kami\\assets\\shader\\fragment";

	for (const auto& file : directory_iterator(path))
	{

		std::ifstream fShaderFile(file.path());
		if (!fShaderFile)
		{
			std::cout << "FAILED TO READ VERTEX SHADER FILE\n";
		}
		std::stringstream fShaderStream;
		fShaderStream << fShaderFile.rdbuf();
		fShaderFile.close();
		std::string vertexCode = fShaderStream.str();

		auto tmp = file.path();
		std::cout << "LOADING VERTEX SHADER FILE : " << tmp.filename().string() << "\n";
		m_fragmentShaderRessources[tmp.filename().string()] = vertexCode;
	}
}


//createShaderPrograms 
//based on the loaded frament and vertex shaders but how should it know which programs to make
//right now i only have one but there are probably cases where you need multiple 
void KamiRessourceCache::createShaderPrograms()
{
	std::string path = "..\\..\\..\\..\\kami\\assets\\shader\\programs\\programs.json";
	std::fstream programFile(path);
	if (!programFile) {
		std::cout << "FAILED TO READ SHADER PROGRAM FILE " << path << "\n";
	}
	json data = json::parse(programFile);
	//in this data i have list of what programsa to make now i need to make them 
	//

	for (auto programData : data["programs"])
	{
		int success;
		char infoLog[512];

		const char* vcode = m_vertexShaderRessources[programData["vertexShaderFileName"].get<std::string>()].c_str();
		const char* fcode = m_fragmentShaderRessources[programData["fragmentShaderFileName"].get<std::string>()].c_str();
		unsigned int vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShaderId, 1, &vcode, NULL);
		glCompileShader(vertexShaderId);
		//CONSIDER right now we don't store compiled vertex and fragment shaders only the programs



		//check compilation result from opengl
		glGetShaderiv(vertexShaderId, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertexShaderId, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		};

		unsigned int fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShaderId, 1, &fcode, NULL);
		glCompileShader(fragmentShaderId);
		//check compilation result 
		glGetShaderiv(fragmentShaderId, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragmentShaderId, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		};


		//would need the name the vertex shader and fragment ids 
		//linkProgram()
		unsigned int shaderProgramId = glCreateProgram();
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

		m_shaderProgramRessources[programData["programName"].get<std::string>()] = shaderProgramId;
	}

}

void KamiRessourceCache::loadTextures()
{
	//read all files in the texutre asset folder
	std::string path = "..\\..\\..\\..\\kami\\assets\\texture";
	using std::filesystem::directory_iterator;

	for (const auto& file : directory_iterator(path))
	{
		stbi_set_flip_vertically_on_load(true);
		//file.path.string.cstr is a bit cringe but works i guess 
		//what is width height and number of channels 

		KamiTexture texture{};
		texture.m_rawTextureData = stbi_load(file.path().string().c_str(), &texture.m_width, &texture.m_height, &texture.m_nrChannels, 0);


		if (!texture.m_rawTextureData)
		{
			std::cout << "RESSOURCE CACHE : FAILED TO LOAD TEXTURE : " << file.path() << "\n";
		}
		m_textureRessources[file.path().filename().string()] = texture;
	}
}