// find
extern void CloseLogFile();

// add
#include <chrono>

struct Timer
{
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration;
	std::string msg;
	Timer(const std::string& str)
	{
		msg = str;
		start = std::chrono::high_resolution_clock::now();
	}
	Timer(const char* c_szFormat, ...)
	{
		va_list args;
		va_start(args, c_szFormat);

		char szBuf[512 + 1];
		int len = _vsnprintf(szBuf, sizeof(szBuf) - 1, c_szFormat, args);

		if (len > 0)
			szBuf[len] = '\0';

		va_end(args);

		msg = std::string(szBuf);
		start = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		end = std::chrono::high_resolution_clock::now();

		duration = end - start;
		float ms = duration.count() * 1000.0f;

		TraceError("[%s] duration(ms): [%f] \n", msg.c_str(), ms);
	}
};