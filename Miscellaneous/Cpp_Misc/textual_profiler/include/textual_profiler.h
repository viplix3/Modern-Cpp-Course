#pragma once

#include <chrono>

namespace TextualProfiler {
class Profiler {
// data members
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> m_startTimePoint;
	void Stop();

public:
	// Constructor
	Profiler();

	// Destructor
	~Profiler();

};
}