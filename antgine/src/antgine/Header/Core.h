#pragma once


#ifdef ANT_PLATFORM_WINDOWS
	#ifdef ANT_BUILD_DLL
		#define ANGINE_API __declspec(dllexport)
	#else
		#define ANGINE_API __declspec(dllimport)
	#endif 

#else
	#error only Windows Supported


#endif


#define BIT(x) (1 << x)