
//then maybe good to have a class that will let us store our textures in some kind of name -> texture map
//and lets us add and remove things from it 

class KamiTexture {

public:
	void readTexture(const char*);
	void createTexture();
	void bindTexture(int);
	void generateTexture();
	~KamiTexture();
	unsigned char* m_data;
	unsigned int m_id;
	int m_width, m_height, m_nrChannels;
private:
};