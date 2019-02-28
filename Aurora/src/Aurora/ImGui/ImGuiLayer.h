#pragma once
#include "Aurora\Layer.h"
#include "Aurora\Events\AppEvent.h"
#include "Aurora\Events\KeyEvent.h"
#include "Aurora\Events\MouseEvent.h"
namespace Aurora {

class AUR_API ImGuiLayer : public Layer {
 public:
  ImGuiLayer();
  ~ImGuiLayer();
  virtual void OnAttach();
  virtual void OnDetach();
  virtual void OnUpdate();
  virtual void OnEvent(Event& e);
private :
	bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
	bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
	bool OnMouseMovedEvent(MouseMovedEvent& e);
	bool OnMouseScrolledEvent(MouseScrolledEvent& e);

	bool OnKeyPressedEvent(keyPressedEvent& e);
	bool OnKeyReleasedEvent(KeyReleasedEvent& e);
	bool OnKeyTypedEvent(KeyTypedEvent& e);
	bool OnWindowResizedEvent(WindowResizeEvent& e);

 private:
  float m_Time = 0.0f;
};

}  // namespace Aurora
