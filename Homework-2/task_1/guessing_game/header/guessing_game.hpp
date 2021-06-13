#pragma once

#ifndef GUESSINGGAME_HPP_
#define GUESSINGGAME_HPP_

#include <random>

namespace guessing_game{
	constexpr int lowIdx = 0;
	constexpr int highIdx = 99;
	int generate_random_num();
	bool check_guess(int, int);
}

#endif