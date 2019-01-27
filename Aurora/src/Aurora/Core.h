#pragma once

#ifdef AUR_PLATFORM_WINDOWS
	#ifdef AUR_BUILD_DLL
		#define AUR_API __declspec(dllexport)
	#else
		#define AUR_API __declspec(dllimport)
	#endif
#else 
#error this only build for windows
#endif



#define AUR_CORE_ERROR(...) ::Aurora::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AUR_CORE_WARN(...) ::Aurora::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AUR_CORE_INFO(...) ::Aurora::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AUR_CORE_TRACE(...) ::Aurora::Log::GetCoreLogger()->trace(__VA_ARGS__)

#define AUR_ERROR(...) ::Aurora::Log::GetCLientLogger()->error(__VA_ARGS__)
#define AUR_WARN(...) ::Aurora::Log::GetCLientLogger()->warn(__VA_ARGS__)
#define AUR_INFO(...) ::Aurora::Log::GetCLientLogger()->info(__VA_ARGS__)
#define AUR_TRACE(...) ::Aurora::Log::GetCLientLogger()->trace(__VA_ARGS__)