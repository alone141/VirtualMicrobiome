#pragma once
bool CheckMapBounds(int x, int y);

template <typename T> int sgn(T val) {
	return (T(0) < val) - (val < T(0));
}