#pragma once
#include "Aurora/Core.h"
#include "spdlog\fmt\bundled\ostream.h"
namespace Aurora {

	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		KeyPressed, KeyReleased,KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved,
		MouseScrolled,

		AppTick, AppUpdate, AppRender
	};
	
	enum EventCategory {
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

	class AUR_API Event
	{
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char * GetEventName() const = 0;
		virtual int GetCategoryFlag() const = 0;
		virtual std::string ToString()const { return GetEventName(); }
		inline bool IsInCategory(EventCategory cat) {
	
			return GetCategoryFlag()& cat;
		}
		bool m_Handled = false; // handled by a layer or not
	protected:

	};

#define EVENT_CLASS_CATEGORY(c) virtual int GetCategoryFlag() const override {return c;}
#define EVENT_CLASS_TYPE(t) static EventType GetStaticType(){return EventType::##t;}\
															virtual EventType GetEventType()const override{return GetStaticType();}\
															virtual const char* GetEventName() const override {return #t;}

	class EventDispatcher
	{
		template <typename T>
		using EventFn = std::function<bool(T&)>;
	public : 
		EventDispatcher(Event& event) :m_event(event) {}
		template<typename T>
		bool Dispatch (EventFn<T> fun){
			if (m_event.GetEventType() == T::GetStaticType()) {
				m_event.m_Handled = fun(*(T*)&m_event);
				return true;
			}
			return false;
		}
	private :
		Event& m_event;
	};


	inline std::ostream& operator <<(std::ostream& os, const Event& e) { return os << e.ToString(); }
}