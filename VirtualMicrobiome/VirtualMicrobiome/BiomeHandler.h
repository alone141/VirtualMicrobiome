#pragma once
#include "Microbiome.h"
class BiomeHandler
{
public:
	Microbiome* microbiome;
	std::vector<std::unique_ptr<Erwinia>> tempE;
	std::vector<std::unique_ptr<Myxococcus>> tempM;
	BiomeHandler(Microbiome* microbiome) : microbiome(microbiome){}
	void Update();
};

