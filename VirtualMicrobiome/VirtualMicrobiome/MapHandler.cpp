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
			if (h->map[y][x] == 1) SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
			else if (h->map[y][x] == 2) SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | BACKGROUND_GREEN);
			else SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
			std::cout << "  ";
		}
		std::cout << std::endl;
	}
}


void MapHandler::Reset()
{
	system("CLS");
}
