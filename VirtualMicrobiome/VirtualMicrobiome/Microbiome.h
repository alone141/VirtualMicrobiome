#pragma once
#include <vector>
#include "Erwinia.h"
#include "Myxococcus.h"
class Microbiome
{
public:
	Microbiome(Habitat* h) {
		this->erwiniaColony->push_back(std::move(std::make_unique<Erwinia>(h)));
		this->myxococcusColony->push_back(std::move(std::make_unique<Myxococcus>(h)));
	}
	std::unique_ptr<std::vector<std::unique_ptr<Erwinia>>> erwiniaColony = 
		std::make_unique<std::vector<std::unique_ptr<Erwinia>>>();

	std::unique_ptr<std::vector<std::unique_ptr<Myxococcus>>> myxococcusColony =
		std::make_unique<std::vector<std::unique_ptr<Myxococcus>>>();
};

