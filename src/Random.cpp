#include "Random.h"
#include <random>

using std::minstd_rand;

namespace ccHelp
{
	minstd_rand randomer;

	void Random::ChangeSeed(int seed)
	{
		randomer.seed(seed);
	}

	
	void Random::ChangeSeed()
	{
		int seed = (int) time(nullptr);
		ChangeSeed(seed);
	}

	
	int Random::RandomInt()
	{
		return randomer();
	}

	
	int Random::RandomNegativeInt()
	{
		return Random::RandomInt() * -1;
	}

	
	int Random::RandomInt(int max)
	{
		if (max < 0)
			return 0;
		return Random::RandomInt(0, max);
	}

	
	int Random::RandomNegativeInt(int min)
	{
		if (min > 0)
			return 0;
		return Random::RandomInt(0, -min) * -1;
	}

	
	int Random::RandomInt(int min, int max)
	{
		if ((max < 0) || (min > max))
			return 0;
		return min + Random::RandomInt() % (max - min);
	}

	
	double Random::RandomDouble()
	{
		return static_cast<double>(Random::RandomInt()) / randomer.max();
	}

	
	double Random::RandomNegativeDouble()
	{
		return Random::RandomDouble() * -1.0;
	}

	
	double Random::RandomDouble(double max)
	{
		if (max < 0.0)
			return 0.0;
		return Random::RandomDouble() * max;
	}

	
	double Random::RandomNegativeDouble(double min)
	{
		if (min > 0)
			return 0;
		return Random::RandomDouble() * min;
	}

	
	double Random::RandomDouble(double min, double max)
	{
		if (min > max)
			return 0;
		return Random::RandomDouble() * (max - min) + min;
	}

	
	float Random::RandomFloat()
	{
		return static_cast<float>(Random::RandomInt()) / randomer.max();
	}

	
	float Random::RandomNegativeFloat()
	{
		return Random::RandomFloat() * -1.f;
	}

	
	float Random::RandomFloat(float max)
	{
		if (max < 0)
			return 0;
		return Random::RandomFloat() * max;
	}

	
	float Random::RandomNegativeFloat(float min)
	{
		if (min > 0)
			return 0;
		return Random::RandomFloat() * min;
	}

	
	float Random::RandomFloat(float min, float max)
	{
		if (min > max)
			return 0;
		return Random::RandomFloat() * (max - min) + min;
	}

	
	char Random::RandomByte()
	{
		return (char) (rand() % 0x100);
	}

	
	char Random::RandomByte(char max)
	{
		return Random::RandomByte() % max;
	}

	char Random::RandomByte(char min, char max)
	{
		return Random::RandomByte(max - min) + min;
	}
	
	bool Random::RandomBool(float trueRatio)
	{
		return (Random::RandomFloat() < trueRatio);
	}

	
	bool Random::RandomBool()
	{
		return Random::RandomBool(0.5f);
	}
}