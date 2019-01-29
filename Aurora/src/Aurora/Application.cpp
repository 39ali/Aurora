#include "Application.h"

namespace Aurora {

	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication)) {
			AUR_TRACE(e.ToString());
			
			
		}
		while (true);
	}
}