#pragma once
#include "Bacteria.h"

class Erwinia :
    public Bacteria<Erwinia>
{
public:

    Erwinia(Habitat* h) : Bacteria(rand() % constant::MAP_SIZE_X, rand() % constant::MAP_SIZE_Y, h, 1) {
        this->expectedLifespan = constant::LIFESPAN_ERWINIA;

    }
    Erwinia(int x, int y, Habitat* h, int shape) : Bacteria(x, y, h, shape, 1) {
        this->expectedLifespan = constant::LIFESPAN_ERWINIA;
    }
    Erwinia(int x, int y, Habitat* h, int shape, float random) : Bacteria(x, y, h, shape, random) {
        this->expectedLifespan = constant::LIFESPAN_ERWINIA;
    }
    ~Erwinia(){}
};

