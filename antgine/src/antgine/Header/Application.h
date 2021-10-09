#pragma once

#include "Core.h"

namespace antgine {


	class ANGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	};
		//to be defined in client
		Application* CreateApplication();
}
