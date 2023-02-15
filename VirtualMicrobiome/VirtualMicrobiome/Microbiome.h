#pragma once
#include <vector>
#include "Erwinia.h"
#include "Myxococcus.h"
class Microbiome
{
public:
	std::unique_ptr<std::vector<std::unique_ptr<Erwinia>>> erwiniaColony = 
		std::make_unique<std::vector<std::unique_ptr<Erwinia>>>();
};

