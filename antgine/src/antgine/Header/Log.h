#pragma once

#include <memory>

#include "Core.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace antgine {


	class ANGINE_API Log
	{

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;


	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; };
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; };



	};
}



#define AG_CORE_FATAL(...) ::antgine::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define AG_CORE_ERROR(...) ::antgine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AG_CORE_WARN(...) ::antgine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AG_CORE_INFO(...) ::antgine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AG_CORE_TRACE(...) ::antgine::Log::GetCoreLogger()->trace(__VA_ARGS__)



#define AG_FATAL(...) ::antgine::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define AG_ERROR(...) ::antgine::Log::GetClientLogger()->error(__VA_ARGS__)
#define AG_WARN(...) ::antgine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AG_INFO(...) ::antgine::Log::GetClientLogger()->info(__VA_ARGS__)
#define AG_TRACE(...) ::antgine::Log::GetClientLogger()->trace(__VA_ARGS__)