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



/// 2^n
#define BIT(x) (1<<x)