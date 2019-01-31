#pragma once 
#include "aurpch.h"
#include "Application.h"
#include "GLFW/glfw3.h"
namespace Aurora {
#define BIND_EVENT_FN(fn) std::bind(&Application::fn, this, std::placeholders::_1) 
	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application() {}

	void Application::OnEvent(Event& e) {

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		AUR_CORE_TRACE("{0}", e.ToString());

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.m_Handled)
				break;
		}
	}


	void Application::PushLayer(Layer* layer) {
		m_LayerStack.PushLayer(layer);
	}
	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
	}

	bool Application ::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	void Application::Run() {
		while (m_Running) {
			auto k = [](){};
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			for (Layer* l : m_LayerStack)
				l->OnUpdate();

			m_Window->OnUpdate();
		
		}
	}
	
}