#pragma once

#include "Constants.h"
#include <vector>
#include <array>
struct Habitat
{
	int map[constant::MAP_SIZE_X][constant::MAP_SIZE_Y] = { {{0}}};
	std::vector<std::array<int, 3>> updatedPixels;

};
