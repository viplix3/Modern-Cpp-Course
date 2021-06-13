#include "guessing_game.hpp"

int guessing_game::generate_random_num(){
	srand(time(NULL));
	int random_number = guessing_game::lowIdx + (rand() % (guessing_game::highIdx - guessing_game::lowIdx + 1));
	return random_number;
}

bool guessing_game::check_guess(int user_input, int random_number){
	return (user_input == random_number);
}