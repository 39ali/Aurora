#include <Aurora.h>


class LayerXP :public Aurora::Layer {

public :
	LayerXP():Layer("layerxp"){}
	
	void OnUpdate() override {
		AUR_INFO("update layerxp");
	}
	void OnEvent(Aurora::Event& e)override {
		AUR_INFO("{0} ",e.ToString());
	}

};


class SandBox :public Aurora::Application {
public:
	SandBox()
	{
		PushLayer(new LayerXP());
	};

	~SandBox()
	{};
};


Aurora::Application* Aurora::CreateApplication() {
	return new SandBox();
}