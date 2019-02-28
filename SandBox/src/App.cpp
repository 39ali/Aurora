#include <Aurora.h>


class LayerXP :public Aurora::Layer {

public :
	LayerXP():Layer("layerxp"){}
	
	void OnUpdate() override {
		
		if (Aurora::Input::IsKeyPressed(AUR_KEY_TAB))
			AUR_INFO("tab key was lit");

	}
	void OnEvent(Aurora::Event& e)override {
		if (e.GetEventType() == Aurora::EventType::KeyPressed)
		{
			Aurora::keyPressedEvent& ee = (Aurora::keyPressedEvent&)e;
			AUR_TRACE("{0}", (char)ee.GetKeyCode());
		}
	}

};


class SandBox :public Aurora::Application {
public:
	SandBox()
	{
		PushLayer(new LayerXP());
		PushLayer(new Aurora::ImGuiLayer());
	};

	~SandBox()
	{};
};


Aurora::Application* Aurora::CreateApplication() {
	return new SandBox();
}