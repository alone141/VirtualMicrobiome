#pragma once
#include "Habitat.h"
#include <stdlib.h>
#include <memory>
template<typename T>
class Bacteria
{
public:
	uint8_t x;
	uint8_t y;
	uint8_t fissionCount = 0;
	uint8_t age = 0;
	float random;
	char shape;
	Habitat* habitat;
	bool readyForFission = constant::READY_FOR_FISSION;
	Bacteria(int x, int y, Habitat* h, int shape) : x(x), y(y), habitat(h), shape(shape), random(1.0) {
		habitat->map[x % constant::MAP_SIZE_X][y % constant::MAP_SIZE_Y] = shape;
	}
	Bacteria(int x, int y, Habitat* h, int shape, float random) : x(x), y(y), habitat(h), shape(shape), random(random) {
		habitat->map[x%constant::MAP_SIZE_X][y % constant::MAP_SIZE_Y] = shape;
	}
	virtual ~Bacteria() {
		habitat->map[this->x][this->y] = 0;
		habitat->updatedPixels.push_back({ this->x,this->y, 0 });
	}
	virtual std::unique_ptr<T> BinaryFission() {
		age++;
		int newPosX = std::abs(this->x + rand() % 3 - 1);
		int newPosY = std::abs(this->y + rand() % 3 - 1);
		if (newPosX >= constant::MAP_SIZE_X || newPosY >= constant::MAP_SIZE_Y) {
			return std::unique_ptr<T>();
		}
		else if (habitat->map[newPosX][newPosY] != 0) {
			return std::unique_ptr<T>();
		}
		else if(readyForFission) {
			habitat->updatedPixels.push_back({ newPosX, newPosY,this->shape });
			return std::make_unique<T>(newPosX,
				newPosY,
				habitat,
				shape
				);
		}
		else return std::unique_ptr<T>();

	}
	virtual void Move() {
		int newPosX = std::abs(this->x + rand() % 3 - 1);
		int newPosY = std::abs(this->y + rand() % 3 - 1);
		if (habitat->map[newPosX][newPosY] == 0 && newPosX < constant::MAP_SIZE_X && newPosY < constant::MAP_SIZE_Y) {
			habitat->updatedPixels.push_back({ this->x,this->y, 0 });
			habitat->map[this->x][this->y] = 0;

			this->x = newPosX;
			this->y = newPosY;
			habitat->updatedPixels.push_back({ newPosX,newPosY, this->shape });
		}

	}

};

