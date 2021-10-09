#pragma once


#ifdef AG_PLATFORM_WINDOWS
	#ifdef AG_BUILD_DLL
		#define ANGINE_API __declspec(dllexport)
	#else
		#define ANGINE_API __declspec(dllimport)
	#endif 

#else
	#error only Windows Supported


#endif
