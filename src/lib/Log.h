
#ifndef LOG_H
#define LOG_H
#include <spdlog/spdlog.h>

namespace CoreLogger {

class Log {
public:
    static void Init();
    inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_Logger; }
private:
    static std::shared_ptr<spdlog::logger> s_Logger;
};

#define LOG_CORE_TRACE(...) ::CoreLogger::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LOG_CORE_INFO(...) ::CoreLogger::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LOG_CORE_WARN(...) ::CoreLogger::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LOG_CORE_ERROR(...) ::CoreLogger::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LOG_CORE_FATAL(...) ::CoreLogger::Log::GetCoreLogger()->fatal(__VA_ARGS__)

} // CoreLogger

#endif //LOG_H
