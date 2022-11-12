
#include "engine/cache/KamiRessourceCache.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <fstream>
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
        json data = json::parse(f);

        m_entityRessources[data["entityName"]] = data;
    }
}
