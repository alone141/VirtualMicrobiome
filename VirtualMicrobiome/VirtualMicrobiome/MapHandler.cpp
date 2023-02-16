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

void MapHandler::PixelDraw(std::vector<std::array<int, 3>>& updatedPx) {
	for (auto& element : updatedPx) {
		COORD position = { element[0] * 2, element[1] }; // Set the position to (10, 5)
		SetConsoleCursorPosition(constant::consoleHandle, position); // Move the cursor to the specified position
		char ch = 'X'; // Character to be written
		DWORD written; // Placeholder for the number of characters actually written
		if (element[2] == 1) SetConsoleTextAttribute(constant::consoleHandle, constant::colors::erwiniaColor);
		else if (element[2] == 2) SetConsoleTextAttribute(constant::consoleHandle, constant::colors::myxcoccusColor);
		else SetConsoleTextAttribute(constant::consoleHandle, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
		WriteConsoleA(constant::consoleHandle, &ch, 1, &written, NULL); // Write the character to the console
		position.X++;
		WriteConsoleA(constant::consoleHandle, &ch, 1, &written, NULL); // Write the character to the console

	}
	updatedPx.clear();
}
void MapHandler::Reset()
{
	system("CLS");
}
