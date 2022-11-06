#include <map>
#include <string>
class KamiTextRessources {
	
public:
	std::map<const std::string,const std::string> m_textRessources
	{
		{"TEST","test string"},
		{"TEST2", "test string2"},
		{"IDS_ALERT", "Alert"},
		{"IDS_QUESTION", "Question"},
		{"IDS_INITIALIZING", "Initializing"}
	};

	std::string getString(std::string key) 
	{
		//if(m_textRessources.contains(key)
		return m_textRessources[key];
	}
	
	//for now i don't see the advantage of laoding it from a xml file 
	//void loadXMLTextRessources(std::string filePath);

};