#pragma once
#include "Event.h"
#include "aurpch.h"
namespace Aurora {
	class MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y) :
			m_MouseX(x), m_MouseY(y) {}
		inline float GetX()const { return m_MouseX; }
		inline float GetY()const { return m_MouseY; }
		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << "," << m_MouseY;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
	private:
		float m_MouseX, m_MouseY;

	};

	class  MouseButtonEvent : public Event {
	public:
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
		inline int GetMouseButton()const { return m_Button; }
	protected:
		MouseButtonEvent(int button) :m_Button(button)
		{}

		int m_Button;
	
	};

	class MouseButtonPressedEvent :public MouseButtonEvent {
	public:
		MouseButtonPressedEvent(int button) :MouseButtonEvent(button) {}
		EVENT_CLASS_TYPE(MouseButtonPressed)
		std::string ToString()const override
		{
			std::stringstream ss;
			ss << "MouseButtonPreessedEvent: " << m_Button;
			return ss.str();
		}

	};

	class MouseButtonReleasedEvent :public MouseButtonEvent {
	public:
		MouseButtonReleasedEvent(int button) :MouseButtonEvent(button) {}
		EVENT_CLASS_TYPE(MouseButtonReleased)
			std::string ToString()const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button;
			return ss.str();
		}

	};

	class MouseScrolledEvent : public Event {
	public:
		MouseScrolledEvent(float xoffset, float yoffset) :
			m_Xoffset(xoffset), m_Yoffset(yoffset) {}
		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
		inline float GetXoffset()const { return m_Xoffset; }
		inline float GetYoffset()const { return m_Yoffset; }
		std::string ToString()const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << m_Xoffset <<", "<< m_Yoffset;
			return ss.str();
		}
	private :
		float m_Xoffset, m_Yoffset;
	};


}