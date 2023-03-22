#pragma once
#include "Bacteria.h"
class Myxococcus : public Bacteria<Myxococcus>
{
public:
    Myxococcus(Habitat* h) : Bacteria(rand() % constant::MAP_SIZE_X, rand() % constant::MAP_SIZE_X, h, 2) {
		this->expectedLifespan = constant::LIFESPAN_MYXOCOCCUS;

	}
	Myxococcus(int x, int y, Habitat* h, int shape) : Bacteria(x, y, h, shape, 2) {
		this->expectedLifespan = constant::LIFESPAN_MYXOCOCCUS;
	}
	Myxococcus(int x, int y, Habitat* h, int shape, float random) : Bacteria(x, y, h, shape, random) {
		this->expectedLifespan = constant::LIFESPAN_MYXOCOCCUS;
	}
	~Myxococcus(){}
};

