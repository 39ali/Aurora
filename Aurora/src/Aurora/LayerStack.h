#pragma once

#include "Aurora\Core.h"
#include "Layer.h"
namespace Aurora {

	class AUR_API LayerStack 
	{
	public :
		LayerStack();
		~LayerStack();
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }
		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
	private:
		std::vector<Layer*> m_Layers;
		std::vector<Layer*>::iterator m_LayerInsert;
	};


}