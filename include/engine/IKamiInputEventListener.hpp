

#ifndef I_KAMI_INPUT_EVENT_LISTENER
#define I_KAMI_INPUT_EVENT_LISTENER
class IKamiInputEventListener {
public:
	virtual void notifyInputEvent(KamiInputEvent) = 0;
	//private EventListener ID ?? so i can delete listeners easily later on
};
#endif