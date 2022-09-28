#include <string>
#include <map>
#include <vector>
class KamiGl {

	//pass in data and the name you want to give to your vbo 
	//create vbo id store it in the map with its name and upload the data to it
	void createVbo();

	//binds a vbo from our map take name as input
	void bind();


	//pass in the file with the contents 
	//do the error handling for the shader compilation
	void createVertexShader();

	//in the destructor make sure to delete all shaders 


private:
	std::map<std::string, unsigned int> vboMap;
	std::map<std::string, unsigned int> vertexShaders;

};