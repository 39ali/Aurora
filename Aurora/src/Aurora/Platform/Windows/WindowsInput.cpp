#include "aurpch.h"
#include "WindowsInput.h"

#include "Aurora/Application.h"
#include "GLFW/glfw3.h"

namespace Aurora {

Input*	Input::s_Instance = new WindowsInput();

bool WindowsInput::IsKeyPressedImpl(int keycode) {
  auto win = static_cast<GLFWwindow*>(
      Application::Get().GetWindow().GetNativeWindow());

  auto state = glfwGetKey(win, keycode);
  return state == GLFW_PRESS || state == GLFW_REPEAT;
}

bool WindowsInput::IsMouseButtonImpl(int button) {
  auto win = static_cast<GLFWwindow*>(
      Application::Get().GetWindow().GetNativeWindow());
  auto state = glfwGetMouseButton(win, button);
  return state == GLFW_PRESS || state == GLFW_REPEAT;
}



std::pair<float, float> WindowsInput::GetMousePosImpl() {
	auto win = static_cast<GLFWwindow*>(
		Application::Get().GetWindow().GetNativeWindow());
	double x, y;
	glfwGetCursorPos(win, &x, &y);
	return { (float)x,(float)y };
}



float WindowsInput::GetMouseXImpl() {
	auto[x, y] = GetMousePosImpl();
	return x;
}
float WindowsInput::GetMouseYImpl() {
  auto [x, y] = GetMousePosImpl();
  return y;
}

}  // namespace Aurora
