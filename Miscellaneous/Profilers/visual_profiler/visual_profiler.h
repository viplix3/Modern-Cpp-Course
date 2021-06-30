// Basic instrumentation profiler. Base code taken from: https://gist.github.com/TheCherno/31f135eea6ee729ab5f26a6908eb3a5e

// Usage: include this header file somewhere in your code (eg. precompiled header), and then use like:
//
// Instrumentor::Get().BeginSession("Session Name");        // Begin session 
// {
//     InstrumentationTimer timer("Profiled Scope Name");   // Place code like this in scopes you'd like to include in profiling
//     // Code
// }
// Instrumentor::Get().EndSession();                        // End Session
//
#pragma once
 
#include <string>
#include <chrono>
#include <algorithm>
#include <fstream>
#include <thread>
#include <mutex>
 
#define PROFILING 1
#ifdef PROFILING
    #define PROFILE_SCOPE(name) InstrumentationTimer timer##__LINE__(name)
    #define PROFILE_FUNCTION()  PROFILE_SCOPE(__PRETTY_FUNCTION__)
#else
    #define PROFILE_SCOPE(name)
#endif

struct ProfileResult
{
    std::string Name;
    long long Start, End;
    uint32_t ThreadID;
};

class Instrumentor {
private:
    std::string m_CurrentSessionName;
    std::ofstream m_OutputStream;
    int m_ProfileCount;
    std::mutex m_lock;
    bool m_activeSession = false;

    Instrumentor() // Our visual profiler is a singleton, so constructor should be private
        : m_CurrentSessionName(nullptr), m_ProfileCount(0)
    {}

public:
    ~Instrumentor() {
        EndSession();
    }

    static Instrumentor& Get() {
        static Instrumentor instance;
        return instance;
    }

    void BeginSession(const std::string& name, const std::string& filepath = "results.json") {
        if(m_activeSession)
            EndSession(); // Clean-up current active session if a new session is started without ending the previous active one
        
        m_OutputStream.open(filepath);
        WriteHeader();
        m_CurrentSessionName = name;
        m_activeSession = true;
    }

    void EndSession() {
        if(!m_activeSession)
            return; // No active session to close

        WriteFooter();
        m_OutputStream.close();
        m_CurrentSessionName = nullptr;
        m_ProfileCount = 0;
        m_activeSession = false;
    }

    void WriteProfile(const ProfileResult& result) {
        std::lock_guard<std::mutex> lock(m_lock);

        if (m_ProfileCount++ > 0)
            m_OutputStream << ",";

        std::string name = result.Name;
        std::replace(name.begin(), name.end(), '"', '\'');

        m_OutputStream << "{";
        m_OutputStream << "\"cat\":\"function\",";
        m_OutputStream << "\"dur\":" << (result.End - result.Start) << ',';
        m_OutputStream << "\"name\":\"" << name << "\",";
        m_OutputStream << "\"ph\":\"X\",";
        m_OutputStream << "\"pid\":0,";
        m_OutputStream << "\"tid\":" << result.ThreadID << ",";
        m_OutputStream << "\"ts\":" << result.Start;
        m_OutputStream << "}";

        m_OutputStream.flush();
    }

    void WriteHeader() {
        m_OutputStream << "{\"otherData\": {},\"traceEvents\":[";
        m_OutputStream.flush();
    }

    void WriteFooter() {
        m_OutputStream << "]}";
        m_OutputStream.flush();
    }


};

class InstrumentationTimer
{
public:
    InstrumentationTimer(const char* name)
        : m_Name(name), m_Stopped(false)
    {
        m_StartTimepoint = std::chrono::high_resolution_clock::now();
    }

    ~InstrumentationTimer()
    {
        if (!m_Stopped)
            Stop();
    }

    void Stop()
    {
        auto endTimepoint = std::chrono::high_resolution_clock::now();

        long long start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
        long long end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();

        uint32_t threadID = std::hash<std::thread::id>{}(std::this_thread::get_id());
        Instrumentor::Get().WriteProfile({ m_Name, start, end, threadID });

        m_Stopped = true;
    }
private:
    const char* m_Name;
    std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;
    bool m_Stopped;
};