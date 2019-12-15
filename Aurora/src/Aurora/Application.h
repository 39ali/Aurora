#pragma once
#include "Core.h"
#include "aurpch.h"
#include "Aurora/Log.h"
#include "Events/AppEvent.h"
#include "Window.h"
#include "Aurora/LayerStack.h"

namespace Aurora {

class Application {
 public:
	 Application();
  virtual ~Application();
  void Run();
  void OnEvent(Event& e);
  void PushLayer(Layer* layer);
  void PushOverlay(Layer* layer);
  inline Window& GetWindow() { return *m_Window; }
  inline static Application& Get() { return *s_Instance; }
private:
	bool OnWindowClose(WindowCloseEvent& e);
private:
	std::unique_ptr<Window> m_Window;
	LayerStack m_LayerStack;
	bool m_Running = true;
private :
	static Application*	s_Instance;
};

Application* CreateApplication();
}  // namespace Aurora
