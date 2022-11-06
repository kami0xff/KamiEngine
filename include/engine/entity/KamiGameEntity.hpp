class KamiGameEntity {

	//maybe a type maybe i need a IGameEntity interface and make multiple types of game entity ?
	//or just make different gameEntityClasses like KamiPlantGameEntity ?
	

	//
	//some kind of Vertex infomration or mesh information to draw the entity to the view 
	

	//KamiTexture entity store texture so that we can draw it 
	// 

	

	//State and properties could vary from entity to entity
		//different property compenents

	//need to be able to load entities on startup from json file 
	//into an entity manager class and then you can just add these already created entities from the json straight into the scene

public:
	unsigned int m_entityId;
	glm::vec3 m_worldPosition;

};