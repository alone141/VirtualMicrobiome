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
	std::vector<std::unique_ptr<Erwinia>> erwiniaVector;
	std::vector<std::unique_ptr<Myxococcus>> myxococcusVector;
	erwiniaVector.push_back(std::move(std::make_unique<Erwinia>(&habitat)));
	myxococcusVector.push_back(std::move(std::make_unique<Myxococcus>(&habitat)));
	MapHandler mapHandler;
	mapHandler.Open();
	mapHandler.Draw(&habitat);
	char temp;
	std::vector<std::unique_ptr<Erwinia>> tempE;
	std::vector<std::unique_ptr<Myxococcus>> tempM;
	while (1) {
		/*std::cin.get(temp);*/
		Sleep(500);
		for (unsigned int i = 0; i < erwiniaVector.size(); i++)
		{
			auto temp2 = erwiniaVector[i]->BinaryFission();
			if (temp2 != nullptr) {
				tempE.push_back(std::move(temp2));
			}
		}
		for (unsigned int i = 0; i < myxococcusVector.size(); i++)
		{
			auto temp1 = myxococcusVector[i]->BinaryFission();
			if (temp1 != nullptr)
			{
				tempM.push_back(std::move(temp1));
			}
		}

		myxococcusVector.reserve(myxococcusVector.size() + tempM.size());
		erwiniaVector.reserve(erwiniaVector.size() + tempE.size());

		for (auto& ptrM : tempM) {
			myxococcusVector.push_back(std::move(ptrM));
		}
		for (auto& ptrE : tempE) {
			erwiniaVector.push_back(std::move(ptrE));
		}
		tempE.clear();
		tempM.clear();
		mapHandler.Draw(&habitat);
	}


}

