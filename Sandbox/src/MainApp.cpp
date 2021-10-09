#include <Antgine.h>


class Main : public antgine::Application {
	public: 
		Main(){

		}
		~Main(){

		}
};

antgine::Application* antgine::CreateApplication() {
	return new Main();
}