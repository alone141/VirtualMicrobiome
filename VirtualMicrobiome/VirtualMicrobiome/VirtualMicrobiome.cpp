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
#include "Microbiome.h"
#include "BiomeHandler.h"
Habitat habitat;
MapHandler mapHandler;
Microbiome microbiome(&habitat);
BiomeHandler biomeHandler(&microbiome);

int main()
{

	srand(std::random_device{}());
	auto hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	mapHandler.Open();
	mapHandler.Draw(&habitat);

	while (1) {
		/*std::cin.get(temp);*/
		Sleep(50);

		biomeHandler.Update();
		mapHandler.PixelDraw(habitat.updatedPixels);
	}
}

