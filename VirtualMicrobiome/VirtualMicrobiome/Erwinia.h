#pragma once
#include "Bacteria.h"

class Erwinia :
    public Bacteria<Erwinia>
{
public:

    Erwinia(Habitat* h, BacteriaFeatures features = constant::ErwiniaFeatures) : Bacteria(rand() % constant::MAP_SIZE_X, rand() % constant::MAP_SIZE_Y, h, 1) {
        this->features = features;
    }
    Erwinia(int x, int y, Habitat* h, int shape, BacteriaFeatures features = constant::ErwiniaFeatures) : Bacteria(x, y, h, shape, 1) {
        this->features = features;

    }
    Erwinia(int x, int y, Habitat* h, int shape, float random, BacteriaFeatures features = constant::ErwiniaFeatures) : Bacteria(x, y, h, shape, random) {
        this->features = features;


    }
    virtual ~Erwinia(){}
};

