#pragma once
#include <memory>
#include <stdlib.h>
#include "Habitat.h"
#include "Utils.h"

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
		age++;

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
			}
		}

	}
	virtual std::array<int, 2> SearchFood() {
		//int tempX;
		//int tempY;
		//for (int itY = 0; itY < this->sight; itY++)
		//{
		//	for (int itX = 0; itX < this->sight; itX++)
		//	{
		//		tempX = this->x + itX;
		//		tempY = this->x + itY;
		//		if (CheckMapBounds(tempX, tempY)) {

		//			if (habitat->map[tempX][tempY] == 'f') {
		//				if (itX < 2 && itY < 2) {
		//					habitat->ChangeLandTo(tempX, tempY, 0);
		//				}
		//				return { +1,+1 };
		//			}
		//		}
		//		tempX = this->x - itX;
		//		tempY = this->x - itY;
		//		if (CheckMapBounds(tempX, tempY)) {

		//			if (habitat->map[tempX][tempY] == 'f') {
		//				if (itX < 2 && itY < 2) {
		//					habitat->ChangeLandTo(tempX, tempY, 0);
		//				}
		//				return { -1,-1 };
		//			}
		//		}
		//	}
		//}
		//return { constant::MAP_SIZE_X + 1,constant::MAP_SIZE_Y + 1 };


		for (int itY = 0; itY < 2*this->sight; itY++)
		{
			for (int itX = 0; itX < 2*this->sight; itX++) {
				if(this->x + itX < constant::MAP_SIZE_X && this->y + itY < constant::MAP_SIZE_Y 
				   && this->x - itX >= 0 && this->y - itY >= 0)
				{
					if (habitat->map[this->x + itX][this->y + itY] == 'f') {
						if (itX < 2 && itY < 2) {
							habitat->map[this->x + itX][this->y + itY] = 0;
							habitat->updatedPixels.push_back({ this->x + itX,this->y + itY,0 });
						}
						else return { sgn(itX), sgn(itY) };
					}
					if (habitat->map[this->x - itX][this->y - itY] == 'f') {
						if (itX < 2 && itY < 2) {
							habitat->map[this->x + itX][this->y + itY] = 0;
							habitat->updatedPixels.push_back({ this->x + itX,this->y + itY,0 });
						}
						else return { sgn(itX), -sgn(itY) };
					}
				}
			}
		}
		return {constant::MAP_SIZE_X+1,constant::MAP_SIZE_Y+1};
	}
	void print_spiral (int ** matrix, int size)
{
		int x = this->x; // current position; x
		int y = this->y; // current position; y
		int d = 0; // current direction; 0=RIGHT, 1=DOWN, 2=LEFT, 3=UP
		int c = 0; // counter
		int s = 1; // chain size

		// starting point
		x = ((int)floor(size/2.0))-1;
		y = ((int)floor(size/2.0))-1;

		for (int k=1; k<=(size-1); k++)
		{
			for (int j=0; j<(k<(size-1)?2:3); j++)
			{
				for (int i=0; i<s; i++)
				{
					std::cout << matrix[x][y] << " ";
					c++;

					switch (d)
					{
						case 0: y = y + 1; break;
						case 1: x = x + 1; break;
						case 2: y = y - 1; break;
						case 3: x = x - 1; break;
					}
				}
				d = (d+1)%4;
			}
			s = s + 1;
		}
}
};

