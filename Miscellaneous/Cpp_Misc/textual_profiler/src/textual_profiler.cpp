#include "textual_profiler.h"
#include <iostream>

namespace TextualProfiler {
Profiler::Profiler() {
	m_startTimePoint = std::chrono::high_resolution_clock::now();
}

Profiler::Profiler(const char* func_name)
	: m_funcName(func_name), m_Stopped(false)
	{
		m_startTimePoint = std::chrono::high_resolution_clock::now();
	}

Profiler::~Profiler() {
	Profiler::Stop();
}

void Profiler::Stop() {
	auto endTimePoint = std::chrono::high_resolution_clock::now();

	auto startTime = std::chrono::time_point_cast<std::chrono::microseconds>(m_startTimePoint).time_since_epoch().count();
	auto endTime = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();

	auto duration  = endTime - startTime;
	double milliSeconds = duration * 0.001;

	if(m_funcName == nullptr)
		std::cout << duration << "uc (" << milliSeconds << "ms)\n";
	else
		std::cout << m_funcName << " : " << duration << "uc (" << milliSeconds << "ms)\n";
}
}