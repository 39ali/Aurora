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


#ifdef  AUR_ENABLE_ASSERT
	#define AUR_ASSERT(x, ...) {if(!(x)){AUR_ERROR("ASSERTION FAILED : {0} ! " , __VA_ARGS__); __debugbreak();  }}
#else 
	#define AUR_ASSERT(x, ...)
#endif //  AUR_ENABLE_ASSERT


/// 2^n
#define BIT(x) (1<<x)