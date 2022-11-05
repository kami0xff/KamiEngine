//  "Mersenne Twister pseudorandom number generator" 
//  Original Code written by Takuji Nishimura and Makoto Matsumoto
//

#include <iostream>
#include <random/KamiRandom.hpp>
#include <chrono> // for std::chrono and get system clock seed

KamiRandom::KamiRandom(void) {
	m_mt = std::mt19937{ static_cast<unsigned int>(std::chrono::steady_clock::now().time_since_epoch().count()) };
	//steady clock guarantees that users cannot alter it
	//seeding the mersenne twister with 8 bytes here could be underseeded but should be fine for now
}

void KamiRandom::test()
{
	for (int count{ 1 }; count <= 40; ++count)
	{
		std::cout << random(1,10) << '\t'; // generate a random number

		// If we've printed 5 numbers, start a new row
		if (count % 5 == 0)
			std::cout << '\n';
	}

};

//PRNGs cannot directly output numbers between x and y 

unsigned long KamiRandom::random(unsigned long start, unsigned long end)
{
	std::uniform_int_distribution distribution {start, end};
	return distribution(m_mt);
}

