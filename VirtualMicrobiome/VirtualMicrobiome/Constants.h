#pragma once
#include <random>
namespace constant {
	static constexpr int MAP_SIZE_X = 50;
	static constexpr int MAP_SIZE_Y = 50;
	static std::mt19937 mersenne_twister{ std::random_device{}() };
	static std::normal_distribution<float> distribution{ 0, 0.2 };
	static inline float AWGN(float stddev = 0.2) {
		static std::normal_distribution<float> distribution{ 0, stddev };
		return distribution(mersenne_twister);
	}
}
