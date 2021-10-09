#pragma once
#include "Application.h"
#ifdef AG_PLATFORM_WINDOWS

extern antgine::Application* antgine::CreateApplication();

int main(int argc,  char** argv) {

	auto app = antgine::CreateApplication();
	app->Run();
	delete app;
}

#endif