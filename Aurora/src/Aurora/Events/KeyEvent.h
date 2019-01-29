#pragma once
#include <sstream>
#include "Event.h"
namespace Aurora {
class AUR_API KeyEvent : public Event {
 public:
  inline int GetKeyCode() const { return m_keycode; }
  EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard)
 protected:
  KeyEvent(int keycode) : m_keycode(keycode) {}
  int m_keycode;
};

class AUR_API keyPressedEvent : public KeyEvent {
 public:
  keyPressedEvent(int keycode, int repeatcount)
      : KeyEvent(keycode), m_RepeatCount(repeatcount) {}
  inline int GetRepeatCount() const { return m_RepeatCount; }
  std::string ToString() const override {
    std::stringstream ss;
    ss << "KeyPressedEvent: " << m_keycode << ":" << m_RepeatCount;
    return ss.str();
  }
  EVENT_CLASS_TYPE(KeyPressed)
 private:
  int m_RepeatCount;
};


class AUR_API KeyReleasedEvent : public KeyEvent
{
public:
	KeyReleasedEvent(int keycode)
		: KeyEvent(keycode) {}

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "KeyReleasedEvent: " << m_keycode;
		return ss.str();
	}

	EVENT_CLASS_TYPE(KeyReleased)
};

}  // namespace Aurora
