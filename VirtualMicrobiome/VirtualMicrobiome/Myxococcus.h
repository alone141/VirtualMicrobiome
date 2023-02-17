#pragma once
#include "Bacteria.h"
class Myxococcus : public Bacteria<Myxococcus>
{
public:
	uint8_t expectedLifespan = constant::LIFESPAN_MYXOCOCCUS;
    Myxococcus(Habitat* h) : Bacteria(rand() % constant::MAP_SIZE_X, rand() % constant::MAP_SIZE_X, h, 2) {
	}
	Myxococcus(int x, int y, Habitat* h, int shape) : Bacteria(x, y, h, shape, 2) {}
	Myxococcus(int x, int y, Habitat* h, int shape, float random) : Bacteria(x, y, h, shape, random) {}
	~Myxococcus(){}
};

