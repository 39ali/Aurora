#pragma once
#include "Aurora\Window.h"
#include "GLFW\glfw3.h"
namespace Aurora {
	class WinWindow : public Window
	{
	public:
		WinWindow(const WindowProps& props);
		virtual ~WinWindow();

		virtual void OnUpdate()override;
		inline  unsigned int GetWidth()const override { return m_Data.Width; };
		inline  unsigned int GetHeight()const override { return m_Data.Height; }
		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool e) override;
		bool IsVSync()const override;
		static Window* Create(const WindowProps& props = WindowProps());
		virtual void* GetNativeWindow() const { return m_Window; };
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
	private:
		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;
			EventCallbackFn EventCallback;
		};
		WindowData m_Data;
		GLFWwindow* m_Window;
	};

}