#pragma once
#include "Application.h"
#ifdef AG_PLATFORM_WINDOWS

extern antgine::Application* antgine::CreateApplication();

int main(int argc,  char** argv) {
	antgine::Log::Init();
	AG_CORE_WARN("Initialized Loggers");
	AG_INFO("Dudeudeu");

	auto app = antgine::CreateApplication();
	app->Run();
	delete app;
}

#endif