#pragma once

#ifdef AUR_PLATFORM_WINDOWS 

#else
	#ifdef AUR_PLATFORM_MACOS

	#else
	 #error this only build for windows and macos
	#endif
#endif


#ifdef  AUR_ENABLE_ASSERT_WINDOWS
	#define AUR_ASSERT(x, ...) {if(!(x)){AUR_ERROR("ASSERTION FAILED : {0} ! " , __VA_ARGS__); __debugbreak();  }}
#else 
	#ifdef AUR_ENABLE_ASSERT_MACOS
	#define AUR_ASSERT(x, ...) {if(!(x)){AUR_ERROR("ASSERTION FAILED : {0} ! " , __VA_ARGS__);  }}
	#else
	#define AUR_ASSERT(x, ...)
	#endif
#endif //  AUR_ENABLE_ASSERT


/// 2^n
#define BIT(x) (1<<x)


#define AUR_BIND_EVENT_FN(fn) std::bind(&fn,this,std::placeholders::_1)