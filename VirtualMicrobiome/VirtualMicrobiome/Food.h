#include "Habitat.h"

class Food
{
public:
	int x;
	int y;
	int calorie;
	int shape = 'f';
	Habitat* habitat;
	Food(Habitat* h) : habitat(h), x(rand() % constant::MAP_SIZE_X), y(rand() % constant::MAP_SIZE_X), calorie(10) {
		habitat->map[x][y] = shape;
		habitat->updatedPixels.push_back({ x,y,shape });
	}
	Food(int x, int y, Habitat* h) : x(x), y(y), habitat(h), calorie(10) {
		habitat->map[x % constant::MAP_SIZE_X][y % constant::MAP_SIZE_Y] = shape;
		habitat->updatedPixels.push_back({ x,y,shape });

	}
};
