#include "Utils.h"
#include "Constants.h"
bool CheckMapBounds(int x, int y) {
	return x < constant::MAP_SIZE_X && y < constant::MAP_SIZE_Y && x >= 0 && y >= 0;
}