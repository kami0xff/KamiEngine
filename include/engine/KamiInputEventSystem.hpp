
#include "engine/IKamiInputEventListener.hpp"
#include <vector>
//this is global scope that is fine i think

//Context of the input 
//some kind of key -> action mapping that can be modified 
//key -> EVENT ?? should my events be like forwards backwards movement 
//or W pressed etc glfw already does that so kinda useless to do it again 
//not sure how i would make it remapable 


//i want a start to this event system the thing that will triger the even is in the glfw process input callback that gets called whenever an input is registered 
//i want to make the fps camera a bit more fps like than the opengl tutorial so the camera should be stuck on the xz plane 
//and to look up and down it will follow the mouse pointer 

//this will hold the list of listeners 
//and notify the listeners of events 



class KamiInputEventSystem {

public:
	//adding listeners ez add at the end 
	//removing listeners dynamically ? how removing in the middle of the vector is it possible ?

	//need something to identify the listeners to be able to remove the desired one 

	void notifyListeners(KamiInputEvent);
	void addListener(const IKamiInputEventListener&);
	void removeListener(const IKamiInputEventListener&);

private:
	std::vector<IKamiInputEventListener> m_listenerVector;

};