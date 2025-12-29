#pragma once
#include "Bacteria.h"
class Myxococcus : public Bacteria<Myxococcus>
{
public:
    Myxococcus(Habitat* h, BacteriaFeatures features = constant::MyxcoccusFeatures) : Bacteria(rand() % constant::MAP_SIZE_X, rand() % constant::MAP_SIZE_X, h, 2) {
		this->features = features;
	}
	Myxococcus(int x, int y, Habitat* h, int shape, BacteriaFeatures features = constant::MyxcoccusFeatures) : Bacteria(x, y, h, shape, 2) {
		this->features = features;


	}
	Myxococcus(int x, int y, Habitat* h, int shape, float random, BacteriaFeatures features = constant::MyxcoccusFeatures) : Bacteria(x, y, h, shape, random) {
		this->features = features;


	}
	~Myxococcus(){}
};

