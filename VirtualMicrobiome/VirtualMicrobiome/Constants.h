#pragma once
#include <random>
#include <windows.h>
#include "BacteriaFeatures.h"

namespace constant {
	static constexpr int SIM_PERIOD = 50;
	inline const HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	static constexpr int MAP_SIZE_X = 50;
	static constexpr int MAP_SIZE_Y = 50;

	static constexpr int LIFESPAN_ERWINIA = 255;
	static constexpr int MOVE_PERIOD_ERW = 1;
	static constexpr int SIGHT_ERW = 35;
	static constexpr int SIZE_ERW = 1;

	static constexpr int LIFESPAN_MYXOCOCCUS = 255;
	static constexpr int MOVE_PERIOD_MYX = 1;
	static constexpr int SIGHT_MYX = 35;
	static constexpr int SIZE_MYX = 5;

	inline constexpr BacteriaFeatures ErwiniaFeatures
	{
		.expectedLifespan = LIFESPAN_ERWINIA,
		.moveAtCycles = MOVE_PERIOD_ERW,
		.sight = SIGHT_ERW,
		.size = SIZE_ERW
	};
	inline constexpr BacteriaFeatures MyxcoccusFeatures
	{
		.expectedLifespan = LIFESPAN_MYXOCOCCUS,
		.moveAtCycles = MOVE_PERIOD_MYX,
		.sight = SIGHT_MYX,
		.size = SIZE_MYX
	};

	static constexpr bool READY_FOR_FISSION = false;
	static constexpr bool CAN_MOVE = true;

	namespace colors
	{
		static constexpr WORD erwiniaColor = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;
		static constexpr WORD myxcoccusColor = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
		static constexpr WORD backgroundColor = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;
		static constexpr WORD foodColor = BACKGROUND_GREEN | FOREGROUND_GREEN;
	}

	inline std::mt19937 mersenne_twister{ std::random_device{}() };

	static inline float AWGN(float stddev = 0.2f) {
		std::normal_distribution<float> dist{ 0.0f, stddev };
		return dist(mersenne_twister);
	}
}
