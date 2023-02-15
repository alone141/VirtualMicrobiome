#include "MapHandler.h"
#include <iostream>
void MapHandler::Open()
{
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	system("CLS");
}


void MapHandler::Draw(Habitat* h)
{
	Reset();
	auto hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int x = 0; x < constant::MAP_SIZE_X; x++)
	{
		for (int y = 0; y < constant::MAP_SIZE_Y; y++)
		{
			if (h->map[y][x] == 1) SetConsoleTextAttribute(hConsole, constant::colors::erwiniaColor);
			else if (h->map[y][x] == 2) SetConsoleTextAttribute(hConsole, constant::colors::myxcoccusColor);
			else SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
			//std::cout << ' ';
			//std::cout << ' ';
			//std::cout << h->map[y][x];
			//std::cout << h->map[y][x];
			printf(" ");
			printf(" ");
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	SetConsoleTextAttribute(hConsole, constant::colors::erwiniaColor);
	std::cout << "  " << "Erwinia ";
	SetConsoleTextAttribute(hConsole, constant::colors::myxcoccusColor);
	std::cout << "  " << "Myxococcus ";

}


void MapHandler::Reset()
{
	system("CLS");
}
