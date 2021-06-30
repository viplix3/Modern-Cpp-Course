#pragma once

#include <chrono>

namespace TextualProfiler {
class Profiler {
// data members
private:
	const char* m_funcName = nullptr;
	std::chrono::time_point<std::chrono::high_resolution_clock> m_startTimePoint;
	bool m_Stopped;
	void Stop();

public:
	// Constructor
	Profiler();
	Profiler(const char* func_name);

	// Destructor
	~Profiler();

};
}