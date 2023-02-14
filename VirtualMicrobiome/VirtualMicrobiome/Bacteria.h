#pragma once
#include "Habitat.h"
#include <stdlib.h>
#include <memory>
template<typename T>
class Bacteria
{
public:
	int x;
	int y;
	float random;
	char shape;
	Habitat* habitat;
	int fissionCount = 0;
	Bacteria(int x, int y, Habitat* h, int shape) : x(x), y(y), habitat(h), shape(shape), random(1.0) {
		h->map[x % constant::MAP_SIZE_X][y % constant::MAP_SIZE_Y] = shape;
	}
	Bacteria(int x, int y, Habitat* h, int shape, float random) : x(x), y(y), habitat(h), shape(shape), random(random) {
		h->map[x%constant::MAP_SIZE_X][y % constant::MAP_SIZE_Y] = shape;
	}
	virtual std::shared_ptr<T> BinaryFission() {
		int newPosX = std::abs(this->x + rand() % 3 - 1);
		int newPosY = std::abs(this->y + rand() % 3 - 1);
		if (habitat->map[newPosX][newPosY] != 0) {
			return std::shared_ptr<T>();
		}
		return std::make_shared<T>(newPosX,
								   newPosY,
								   habitat, 
								   shape, 
								   random + random*constant::AWGN()
								  );
	}
};

