﻿#include <iostream>
#include <io.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include "Habitat.h"
#include "Bacteria.h"
#include "Erwinia.h"
#include "Myxococcus.h"
#include "MapHandler.h"
Habitat habitat;
int main()
{
	srand(time(0));
	auto hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::vector<std::shared_ptr<Erwinia>> erwiniaVector;
	std::vector<std::shared_ptr<Myxococcus>> myxococcusVector;
	auto erwiniaZero = std::make_shared<Erwinia>(&habitat);
	auto myxococcusZero = std::make_shared<Myxococcus>(&habitat);
	erwiniaVector.push_back(erwiniaZero);
	myxococcusVector.push_back(myxococcusZero);
	MapHandler mapHandler;
	mapHandler.Open();
	mapHandler.Draw(&habitat);
	char temp;
	std::vector<std::shared_ptr<Erwinia>> tempE;
	std::vector<std::shared_ptr<Myxococcus>> tempM;
	while (1) {
		std::cin.get(temp);
		for (unsigned int i = 0; i < erwiniaVector.size(); i++)
		{
			auto temp2 = erwiniaVector[i]->BinaryFission();
			if (temp2 != nullptr) {
				tempE.push_back(temp2);
			}
		}
		for (unsigned int i = 0; i < myxococcusVector.size(); i++)
		{
			auto temp1 = myxococcusVector[i]->BinaryFission();
			if (temp1 != nullptr)
			{
				tempM.push_back(temp1);
			}
		}
		myxococcusVector.insert(myxococcusVector.end(), tempM.begin(), tempM.end());
		erwiniaVector.insert(erwiniaVector.end(), tempE.begin(), tempE.end());
		tempE.clear();
		tempM.clear();
		mapHandler.Draw(&habitat);
	}


}

