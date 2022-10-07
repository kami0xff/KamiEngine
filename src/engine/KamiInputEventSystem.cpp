#include "engine/KamiInputEventSystem.hpp"
#include "engine/KamiInputEvent.hpp"

void KamiInputEventSystem::notifyListeners(KamiInputEvent eventType) {
	for (auto listener : m_listenerVector) {
		listener.notifyInputEvent(eventType);
	}
};

void KamiInputEventSystem::addListener(const IKamiInputEventListener& newListener) {
	m_listenerVector.push_back(newListener);
};

void KamiInputEventSystem::removeListener(const IKamiInputEventListener& listenerToRemove) {
	//how to find and resize the vector ??????
	//m_listenerVector.find
};

//do i need this runtime polymorphism 
//its nice to be able to code it like this but if its slow 
//