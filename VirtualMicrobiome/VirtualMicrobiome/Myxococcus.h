#pragma once
#include "Bacteria.h"
class Myxococcus :
    public Bacteria<Myxococcus>
{
public:
    Myxococcus(Habitat* h) : Bacteria(rand() % 100, rand() % 100, h, 2) {}
	Myxococcus(int x, int y, Habitat* h, int shape) : Bacteria(x, y, h, shape, 1) {}
	Myxococcus(int x, int y, Habitat* h, int shape, float random) : Bacteria(x, y, h, shape, random) {}
};

