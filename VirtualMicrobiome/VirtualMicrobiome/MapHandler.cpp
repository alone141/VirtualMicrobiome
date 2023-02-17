#include "MapHandler.h"
#include <iostream>
void MapHandler::Open()
{
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	SetConsoleTitleA("Muazzam");
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
			ColorPicker(h->map[y][x]);
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
		COORD position; // Set the position to (10, 5)
		char ch = 'X'; // Character to be written
		DWORD written; // Placeholder for the number of characters actually written
	for (auto& element : updatedPx) {

		ColorPicker(element[2]);
		position.X = element[0] * 2;
		position.Y = element[1];
		SetConsoleCursorPosition(constant::consoleHandle, position); // Move the cursor to the specified position

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
void MapHandler::ColorPicker(int shp) {
	if (shp == 1) SetConsoleTextAttribute(constant::consoleHandle, constant::colors::erwiniaColor);
	else if (shp == 2) SetConsoleTextAttribute(constant::consoleHandle, constant::colors::myxcoccusColor);
	else if (shp == 'f') SetConsoleTextAttribute(constant::consoleHandle, constant::colors::foodColor);
	else SetConsoleTextAttribute(constant::consoleHandle, constant::colors::backgroundColor);
}