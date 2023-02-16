#pragma once
#include <vector>
#include "Erwinia.h"
#include "Myxococcus.h"
using AllSpecies = std::tuple<Erwinia, Myxococcus>;

template<typename Tuple>
struct GenericBiomeHandler;

template<typename... Args>
struct GenericBiomeHandler<std::tuple<Args...>> {
    Microbiome* microbiome;
    GenericBiomeHandler<std::tuple<Args...>>(Microbiome* microbiome) : microbiome(microbiome) {}

    constexpr void operator()() {
        (Update<Args>(microbiome), ...);
    }
};


template <typename T>
void Update(Microbiome* m) {
    std::vector<std::unique_ptr<T>> tempColony;
    std::shared_ptr<std::vector<std::unique_ptr<T>>> colony = std::get<std::shared_ptr<std::vector<std::unique_ptr<T>>>>(m->colonies);
    for (unsigned int i = 0; i < colony->size(); i++)
    {
        if((*colony)[i] != nullptr)
        {
            if ((*colony)[i]->age > (*colony)[i]->expectedLifespan) {
                (*colony)[i].reset(); //kader
            }
            else
            {
                auto temp2 = (*colony)[i]->BinaryFission();
                if (temp2 != nullptr) {
                    tempColony.push_back(std::move(temp2));
                }
            }
        }

    }
    colony->reserve(colony->size() + tempColony.size());

    for (auto& itr : tempColony) {
        colony->push_back(std::move(itr));
    }
}
