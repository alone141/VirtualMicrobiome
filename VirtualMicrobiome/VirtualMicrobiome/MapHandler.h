#pragma once
#include <windows.h>
#include <stdlib.h>
#include "Habitat.h"

class MapHandler
{
public:
	HANDLE handler;
	void Open();
	void Draw(Habitat* h);
	void Reset();
};

