

cmake_minimum_required (VERSION 3.20)
project (engine LANGUAGES CXX )
set(CMAKE_CXX_STANDARD 20)

#set(PostgreSQL_INCLUDE_DIR "C:/PostgreSQL/14/include")
#set(PostgreSQL_LIBRARY_DIR "C:/PostgreSQL/14/lib")
#set(PostgreSQL_ROOT "C:/PostgreSQL/14")

add_subdirectory("external/glfw")
add_subdirectory("external/glm")
add_subdirectory("external/fmt")
add_subdirectory("external/glad")
#add_subdirectory("external/libpqxx" build-pqxx)
add_subdirectory("external/json")
#strange stfuff with boost 
#add_subdirectory("external/asio")
#add_subdirectory("external/openal-soft")

#to avoid having to manually change the files below 
#apparently inneficient for very large projects
file(GLOB SOURCES "src/*.cpp", "src/*/*.cpp", "src/*/*/*.cpp")


add_library(${PROJECT_NAME} ${SOURCES})


#this is important when you are building libraries 
#intuitively i think it will add the include directories path to my build
#lookup these two target function and add lib in the doc 

target_include_directories(${PROJECT_NAME} 
	PUBLIC
		#public headers that we will allow access to in the application layer
		$<INSTALL_INTERFACE:include> #will install the libraries and include them 
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> #this should help with static libraries
		glm
		fmt
		glfw
		glad
		nlohmann_json
	PRIVATE
		"external/stb" #header files only 
)


target_link_libraries(${PROJECT_NAME}
	PUBLIC 
		glm
		fmt
		glfw
		glad
		nlohmann_json
	PRIVATE
)