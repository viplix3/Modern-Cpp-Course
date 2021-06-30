#include <iostream>
#include <stdlib.h>

#include "textual_profiler.h"
#include "visual_profiler.h"

void print_hello_world() {
	PROFILE_FUNCTION();
	TextualProfiler::Profiler time("print_hello_world()");
	std::cout << "\nHello World" << std::endl;
}

int main() {
	Instrumentor::Get().BeginSession("main", "/home/viplix3/GitHub/Modern-Cpp-Course/Miscellaneous/Profilers/main/results.json");
	print_hello_world();

	{
		PROFILE_SCOPE("printf");
		TextualProfiler::Profiler time;
		printf("\nHello World using printf\n");
	}

	{
		PROFILE_SCOPE("std::cout");
		TextualProfiler::Profiler time("std::cout");
		std::cout << "\nHello world using std::cout\n";
	}

	{
		PROFILE_SCOPE("std::endl");
		TextualProfiler::Profiler time;
		std::cout << std::endl << "Hello world using std::cout and std::endl" << std::endl;
	}

	Instrumentor::Get().EndSession();

	return EXIT_SUCCESS;
}