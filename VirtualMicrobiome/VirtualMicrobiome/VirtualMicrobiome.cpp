#include <iostream>
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
		for (unsigned int i = 0; i < myxococcusVector.size(); i++)
		{

			tempM.push_back(myxococcusVector[i]->BinaryFission());
		}
		for (unsigned int i = 0; i < erwiniaVector.size(); i++)
		{
			tempE.push_back(erwiniaVector[i]->BinaryFission());
		}
		myxococcusVector.insert(myxococcusVector.end(), tempM.begin(), tempM.end());
		erwiniaVector.insert(erwiniaVector.end(), tempE.begin(), tempE.end());
		tempE.clear();
		tempM.clear();
		//for (auto& element : myxococcusVector) myxococcusVector.push_back(element->BinaryFission());
		//for (auto& element : erwiniaVector) erwiniaVector.push_back(element->BinaryFission());
		mapHandler.Draw(&habitat);
	}


}

