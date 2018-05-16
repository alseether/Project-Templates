#ifndef RAND_HPP
#define RAND_HPP

#include <random>

class Rand {
public:
	Rand() :
		gen(rd())
	{
	}

	Rand(long seed):
		gen(seed)
	{
	
	}

	int getRandom(int from, int to){
		std::uniform_int_distribution<> dis(from, to);
		return dis(gen);
	}

	unsigned int getRandom(unsigned int from, unsigned int to){
		std::uniform_int_distribution<unsigned> dis(from, to);
		return dis(gen);
	}

	double getRandom(double from, double to){
		std::uniform_real_distribution<> dis(from, to);
		return dis(gen);
	}

private:
	std::random_device rd;
	std::mt19937 gen;
};

#endif