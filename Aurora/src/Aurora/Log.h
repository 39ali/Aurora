#pragma once

#include "Aurora\Core.h"
#include "spdlog\spdlog.h"
namespace Aurora {
	class AUR_API Log
	{
	public:
		Log();
		~Log();
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger()
		{
			return s_CoreLogger;
		}
		inline static std::shared_ptr<spdlog::logger>& GetCLientLogger()
		{
			return s_ClientLogger;
		}
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}


#define AUR_CORE_ERROR(...) ::Aurora::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AUR_CORE_WARN(...) ::Aurora::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AUR_CORE_INFO(...) ::Aurora::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AUR_CORE_TRACE(...) ::Aurora::Log::GetCoreLogger()->trace(__VA_ARGS__)

#define AUR_ERROR(...) ::Aurora::Log::GetCLientLogger()->error(__VA_ARGS__)
#define AUR_WARN(...) ::Aurora::Log::GetCLientLogger()->warn(__VA_ARGS__)
#define AUR_INFO(...) ::Aurora::Log::GetCLientLogger()->info(__VA_ARGS__)
#define AUR_TRACE(...)	::Aurora::Log::GetCLientLogger()->trace(__VA_ARGS__)



//trace - gray 
//info  -green
//warn - yellow
// error -red  
