#pragma once
#include "Aurora\Core.h"
#include "aurpch.h"
#include "Events\Event.h"
namespace Aurora {

	struct WindowProps {
		std::string Title;
		unsigned int Width, Height;
		WindowProps(const std::string& title="AUR ENGINE", unsigned int 
		width = 1280,unsigned int height=720):Title(title),Width(width),Height(height) {}

	};
	class AUR_API Window {
	public :
	
		virtual ~Window() {}
		virtual void OnUpdate() = 0;
		virtual unsigned int GetWidth()const = 0;
		virtual unsigned int GetHeight()const = 0;
		virtual void SetVSync(bool e) = 0;
		virtual bool IsVSync()const = 0;
		
		using EventCallbackFn = std::function<void(Event&)>;
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		static Window* Create(const WindowProps& props = WindowProps());


	};
}