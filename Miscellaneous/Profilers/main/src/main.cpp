#include <iostream>
#include <stdlib.h>

#include "textual_profiler.h"
#include "../../visual_profiler/include/visual_profiler.h"

int main() {
	{
		PROFILE_SCOPE("printf");
		TextualProfiler::Profiler time;
		printf("\nHello World using printf\n");
	}

	{
		TextualProfiler::Profiler time("std::cout");
		std::cout << "\nHello world using std::cout\n";
	}

	{
		TextualProfiler::Profiler time;
		std::cout << std::endl << "Hello world using std::cout and std::endl" << std::endl;
	}

	return EXIT_SUCCESS;
}