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
	uint8_t sight = constant::SIGHT_BACTERIA;
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
		int newPosX;
		int newPosY;
		auto foodDirection = SearchFood();
		if (foodDirection[0] < constant::MAP_SIZE_X && foodDirection[1] < constant::MAP_SIZE_Y) {
			newPosX = this->x + foodDirection[0];
			newPosY = this->y + foodDirection[1];
		}
		else {
			newPosX = std::abs(this->x + rand() % 3 - 1);
			newPosY = std::abs(this->y + rand() % 3 - 1);
		}

		if (habitat->map[newPosX][newPosY] == 0 && newPosX < constant::MAP_SIZE_X && newPosY < constant::MAP_SIZE_Y) {
			habitat->updatedPixels.push_back({ this->x,this->y, 0 });
			habitat->map[this->x][this->y] = 0;

			this->x = newPosX;
			this->y = newPosY;
			habitat->updatedPixels.push_back({ newPosX,newPosY, this->shape });
		}

	}
	std::array<int, 2> SearchFood() {
		for (int itX = 0; itX < 2 * this->sight; itX++)
		{
			for (int itY = 0; itY < 2 * this->sight; itY++)
			{
				if (this->x - this->sight >= 0) {
					if (habitat->map[this->x + itX - this->sight][this->y + itY - this->sight] == 'f') {
						int foodX = this->x + itX - this->sight;
						int foodY = this->y + itY - this->sight;
						return { sgn(foodX), sgn(foodY)};
					}
				}
			}
		}
		return {constant::MAP_SIZE_X+1,constant::MAP_SIZE_Y+1};
	}
	template <typename T> int sgn(T val) {
		return (T(0) < val) - (val < T(0));
	}
};

