#pragma once
#include <random>
#include <windows.h>
namespace constant {
	static const HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	static constexpr int MAP_SIZE_X = 50;
	static constexpr int MAP_SIZE_Y = 50;
	static constexpr int LIFESPAN_ERWINIA = 255;
	static constexpr int LIFESPAN_MYXOCOCCUS = 255;
	static constexpr uint8_t SIGHT_BACTERIA = 255;
	static constexpr bool READY_FOR_FISSION = false;
	static constexpr bool CAN_MOVE = true;
	namespace colors
	{
		static constexpr int erwiniaColor = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;
		static constexpr int myxcoccusColor = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
		static constexpr int backgroundColor = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;
		static constexpr int foodColor = BACKGROUND_GREEN | FOREGROUND_GREEN;
	}

	static std::mt19937 mersenne_twister{ std::random_device{}() };
	static std::normal_distribution<float> distribution{ 0, 0.2 };        
	static inline float AWGN(float stddev = 0.2) {
		static std::normal_distribution<float> distribution{ 0, stddev };
		return distribution(mersenne_twister);
	}
}
