#include <iostream>
#include <stdlib.h>
#include "guessing_game.hpp"

int main(){
	int user_input;

	std::cout<< "Welcome to the number guessing game\n" << std::endl;

	std::cout << "Generating a random number.." << std::endl;
	int random_number = guessing_game::generate_random_num();
	std::cout<< "Random number generated" << std::endl;

	while(true){
		std::cout<< "\nPlease enter a number between 0 and 99: ";
		std::cin >> user_input;

		if(std::cin.fail()){
			std::cerr << "Error encountered, exiting..." << std::endl;
			std::cout << "Magic number was: " << random_number << std::endl;
			return EXIT_FAILURE;
		}

		if(user_input < 0 || 100 < user_input){
			std::cerr << "[WARNING] : Number must be between 0 and 99" << std::endl;
			continue;
		}
		else if(guessing_game::check_guess(user_input, random_number)){
			std::cout << "Congratulation! You've guessed the correct number: " << random_number << std::endl;
			break;
		}
		else{
			std::cout << "Oh no, the guessed number is not corect." << std::endl;
			
			if(random_number < user_input)
				std::cout << "The magic number is less than the guess." << std::endl;
			else
				std::cout << "The magic number is greater than the guess." << std::endl;
			continue;
		}
	}
	return EXIT_SUCCESS;
}