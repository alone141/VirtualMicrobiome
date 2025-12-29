#pragma once

#include "Constants.h"
#include <vector>
#include <array>
#include <unordered_map>
struct Habitat
{
	int map[constant::MAP_SIZE_X][constant::MAP_SIZE_Y] = { {{0}}};
	std::vector<std::array<int, 3>> updatedPixels;
    std::unordered_map<int, int> shapeCounts;

    void ChangeLandTo(int x, int y, int shape) {
        this->map[x][y] = shape;
        this->updatedPixels.push_back({ x,y,shape });
        this->shapeCounts[shape]++;
    }

    int GetShapeCount(int shape) {
        return shapeCounts[shape];
    }
};
