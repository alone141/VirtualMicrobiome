#include "BiomeHandler.h"

void BiomeHandler::Update() {
	for (unsigned int i = 0; i < microbiome->erwiniaColony->size(); i++)
	{
		auto temp2 = (*microbiome->erwiniaColony)[i]->BinaryFission();
		if (temp2 != nullptr) {
			tempE.push_back(std::move(temp2));
		}
	}
	for (unsigned int i = 0; i < microbiome->myxococcusColony->size(); i++)
	{
		auto temp1 = (*microbiome->myxococcusColony)[i]->BinaryFission();
		if (temp1 != nullptr)
		{
			tempM.push_back(std::move(temp1));
		}
	}

	microbiome->myxococcusColony->reserve(microbiome->myxococcusColony->size() + tempM.size());
	microbiome->erwiniaColony->reserve(microbiome->erwiniaColony->size() + tempE.size());

	for (auto& ptrM : tempM) {
		microbiome->myxococcusColony->push_back(std::move(ptrM));
	}
	for (auto& ptrE : tempE) {
		microbiome->erwiniaColony->push_back(std::move(ptrE));
	}
	tempE.clear();
	tempM.clear();
}