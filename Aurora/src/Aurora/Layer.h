#pragma once
#include "Core.h"
#include "Events/Event.h"
namespace Aurora {

	class Layer {
	public:
		Layer(const std::string& name = "Layer00") :
			m_Name(name) {}
		virtual ~Layer() {}
		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& e) {}
		inline const std::string & GetName()const { return m_Name; }
	private :
		std::string m_Name;



	};

}
