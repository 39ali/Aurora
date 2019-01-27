#include <Aurora.h>



class SandBox :public Aurora::Application {
public:
	SandBox()
	{};

	~SandBox()
	{};
};


Aurora::Application* Aurora::CreateApplication() {
	return new SandBox();
}