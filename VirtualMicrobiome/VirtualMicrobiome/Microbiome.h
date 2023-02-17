#pragma once
#include <vector>
#include "Erwinia.h"
#include "Myxococcus.h"

class Microbiome
{
public:
	Habitat* habitat;
	Microbiome(Habitat* h) : habitat(h) {
		srand(std::random_device{}());

		this->erwiniaColony->push_back(std::move(std::make_unique<Erwinia>(h)));
		this->myxococcusColony->push_back(std::move(std::make_unique<Myxococcus>(h)));
		colonies = std::make_tuple(erwiniaColony, myxococcusColony);
	}
	std::shared_ptr<std::vector<std::unique_ptr<Erwinia>>> erwiniaColony = 
		std::make_shared<std::vector<std::unique_ptr<Erwinia>>>();

	std::shared_ptr<std::vector<std::unique_ptr<Myxococcus>>> myxococcusColony =
		std::make_shared<std::vector<std::unique_ptr<Myxococcus>>>();

	std::tuple<std::shared_ptr<std::vector<std::unique_ptr<Erwinia>>>, std::shared_ptr<std::vector<std::unique_ptr<Myxococcus>>>> colonies;
};

