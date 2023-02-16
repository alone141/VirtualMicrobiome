#include <iostream>
#include <io.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <tuple>
#include "Habitat.h"
#include "Bacteria.h"
#include "Erwinia.h"
#include "Myxococcus.h"
#include "MapHandler.h"
#include "Microbiome.h"
#include "BiomeHandler.h"
#include "GenericBiomeHandler.h"
Habitat habitat;
MapHandler mapHandler;
Microbiome microbiome(&habitat);
GenericBiomeHandler<AllSpecies> genericBiomeHandler(&microbiome);

int main()
{

	srand(std::random_device{}());
	mapHandler.Open();
	mapHandler.Draw(&habitat);

	while (1) {
		/*std::cin.get(temp);*/
		Sleep(1);


		genericBiomeHandler();
		mapHandler.PixelDraw(habitat.updatedPixels);
	}
}

