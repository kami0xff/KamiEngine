//  "Mersenne Twister pseudorandom number generator" 
//  Original Code written by Takuji Nishimura and Makoto Matsumoto
//
#include <random>

class KamiRandom {
	std::mt19937 m_mt; //32 is enough number between 0 and 4 billion atm
	//need to seed with something that changes each program run at construction
public:
	KamiRandom(void);

	void test();
	
	//returns unsigned long between start and end
	unsigned long random(unsigned long start, unsigned long end);

};