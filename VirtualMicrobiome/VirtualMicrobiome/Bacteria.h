#pragma once
#include <memory>
#include <stdlib.h>
#include "Habitat.h"
#include "Utils.h"

template<typename T>
class Bacteria
{
public:
	uint8_t weight=0;
	uint8_t moveAtCycles;
	uint8_t expectedLifespan = 5;
	uint8_t x;
	uint8_t y;
	uint8_t fissionCount = 0;
	uint8_t age = 0;
	uint8_t sight = constant::SIGHT_BACTERIA;
	uint8_t size = 10;
	float energy = 100;
	float random;
	char shape;
	Habitat* habitat;
	bool readyForFission = constant::READY_FOR_FISSION;
	bool canMove = constant::CAN_MOVE;
	Bacteria(int x, int y, Habitat* h, int shape) : x(x), y(y), habitat(h), shape(shape), random(1.0) {
		habitat->map[x % constant::MAP_SIZE_X][y % constant::MAP_SIZE_Y] = shape;
	}
	Bacteria(int x, int y, Habitat* h, int shape, float random) : x(x), y(y), habitat(h), shape(shape), random(random) {
		habitat->map[x%constant::MAP_SIZE_X][y % constant::MAP_SIZE_Y] = shape;
	}
	virtual ~Bacteria() {
		habitat->ChangeLandTo(this->x, this->y, 0);
	}
	virtual std::unique_ptr<T> BinaryFission() {
		int newPosX = std::abs(this->x + rand() % 3 - 1);
		int newPosY = std::abs(this->y + rand() % 3 - 1);
		if (!CheckMapBounds(newPosX,newPosY)) {
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
		if(canMove)
		{
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

			if (habitat->map[newPosX][newPosY] == 0 && CheckMapBounds(newPosX,newPosY)) {

				habitat->ChangeLandTo(this->x, this->y, 0);
				this->x = newPosX;
				this->y = newPosY;
				habitat->updatedPixels.push_back({ newPosX,newPosY, this->shape });
				EnergyChange(-1.0/(this->moveAtCycles * this->moveAtCycles)*constant::SIZE_ERW);
			}

		}

	}
	virtual std::array<int, 2> SearchFood() {
		int x = this->x; 
		int y = this->y; 
		int direction = 0; //0=RIGHT, 1=DOWN, 2=LEFT, 3=UP
		int counter = 0; 
		int chainSize = 1;

		for (int k = 1; k <= (this->sight - 1); k++)
		{
			for (int j = 0; j < (k < (this->sight - 1) ? 2 : 3); j++)
			{
				for (int i = 0; i < chainSize; i++)
				{
					//std::cout << habitat->map[x][y] << " ";
					counter++;

					switch (direction)
					{
					case 0: y = y + 1; break;
					case 1: x = x + 1; break;
					case 2: y = y - 1; break;
					case 3: x = x - 1; break;
					}
					if (habitat->map[x][y] == 'f' && CheckMapBounds(x,y)) {
						if (std::abs(this->x - x) < 2 && std::abs(this->y - y) < 2) {
							habitat->map[x][y] = 0;
							habitat->updatedPixels.push_back({ x,y,0 });
							EnergyChange(20);
							return { constant::MAP_SIZE_X + 1,constant::MAP_SIZE_Y + 1 };
						}
						else return { sgn(-this->x + x), sgn(-this->y + y) };
					}
				}
				direction = (direction + 1) % 4;
			}
			chainSize = chainSize + 1;
		}

		return {constant::MAP_SIZE_X+1,constant::MAP_SIZE_Y+1};
	}
	virtual void EnergyChange(float x) {
		this->energy += x;
	}
	virtual int Update() {
		age++;
		EnergyChange(-1);
		if (!(age % this->moveAtCycles)) {
			this->Move();
		}
		if (energy <= 0 || age > this->expectedLifespan) {
			return 0;
		}
		else {
			return 1;
		}
	}
};

