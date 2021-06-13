#include <iostream>
#include <stdlib.h>

constexpr int MAX_ARGS = 3;

int main(int argc, char** argv){

	if(argc != MAX_ARGS){
		std::cerr << "Invalid number of arguments provided, exiting.." << std::endl;
		return EXIT_FAILURE;
	}

	int file_1_num, file_2_num;
	std::string file_1_ext, file_2_ext;

	std::string file_1_name = argv[1];
	std::string file_2_name = argv[2];

	return EXIT_SUCCESS;
}