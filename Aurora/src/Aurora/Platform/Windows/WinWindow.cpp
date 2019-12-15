#include "aurpch.h"
#include "WinWindow.h"
#include "Aurora/Events/AppEvent.h"
#include "Aurora/Events/KeyEvent.h"
#include "Aurora/Events/MouseEvent.h"
#include "Aurora/Log.h"
#include "glad/glad.h"

namespace Aurora {

static bool s_GLFWInit = false;
WinWindow::WinWindow(const WindowProps& props) { Init(props); }

WinWindow::~WinWindow() { Shutdown(); }

void WinWindow::Init(const WindowProps& props) {
  m_Data.Title = props.Title;
  m_Data.Width = props.Width;
  m_Data.Height = props.Height;

  AUR_CORE_INFO("Creating Window {0} ({1}, {2})", m_Data.Title, m_Data.Width,
                m_Data.Height);
  if (!s_GLFWInit) {
    int succ = glfwInit();
	glfwSetErrorCallback([](int error, const char* description) 
	{
		AUR_ERROR("GLFW FATAL ERROR {0}: {1}", error,description);
	});
    AUR_ASSERT(succ, "Could not intialize GLFW!");

    s_GLFWInit = true;
  }
    /// we need this for macos to work
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    m_Window = glfwCreateWindow(props.Width, props.Height, props.Title.c_str(),
                              nullptr, nullptr);
  glfwMakeContextCurrent(m_Window);

  int stat = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
  AUR_ASSERT(stat, "failed to load GLAD!");
  
  printf("OpenGL version supported by this platform (%s): \n", glGetString(GL_VERSION));
  
  glfwSetWindowUserPointer(m_Window, &m_Data);
  SetVSync(true);

  /// set glfw Event callbacks
  glfwSetWindowSizeCallback(
      m_Window, [](GLFWwindow* window, int width, int height) {
        
	  WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

        WindowResizeEvent e(width, height);
        data.Width = width;
        data.Height = height;
        data.EventCallback(e);
      });

  glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {
    WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
    WindowCloseEvent event;
    data.EventCallback(event);
  });

  glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode,
                                  int action, int mods) {
    WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
    switch (action) {
      case GLFW_PRESS: {
        keyPressedEvent event(key, 0);
        data.EventCallback(event);
        break;
      }
      case GLFW_RELEASE: {
        KeyReleasedEvent event(key);
        data.EventCallback(event);
        break;
      }
      case GLFW_REPEAT: {
        keyPressedEvent event(key, 1);
        data.EventCallback(event);
        break;
      }
    }
  });

  glfwSetMouseButtonCallback(
      m_Window, [](GLFWwindow* window, int button, int action, int mode) {
        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
        switch (action) {
          case GLFW_PRESS: {
            MouseButtonPressedEvent event(button);
            data.EventCallback(event);
            break;
          }
          case GLFW_RELEASE: {
            MouseButtonReleasedEvent event(button);
            data.EventCallback(event);
            break;
          }
        }
      });
 
  glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int character) {
	  WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
	  KeyTypedEvent e(character);
	  data.EventCallback(e);

  });

  glfwSetCursorPosCallback(m_Window,[](GLFWwindow* window , double xpos, double ypos) 
  {
	  WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
	  MouseMovedEvent e((float)xpos, (float)ypos);
	  data.EventCallback(e);
  });


  glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xoffset
	  , double yoffset) {
	  MouseScrolledEvent event(xoffset, yoffset);
	  WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
	  data.EventCallback(event);
	
  });
}

void WinWindow::Shutdown() { glfwDestroyWindow(m_Window); }

Window* Window::Create(const WindowProps& props) {
  return new WinWindow(props);
}

void WinWindow::OnUpdate() {
  glfwPollEvents();
  glfwSwapBuffers(m_Window);
}

void WinWindow::SetVSync(bool e) {
  if (e)
    glfwSwapInterval(1);
  else
    glfwSwapInterval(0);
  m_Data.VSync = e;
}
bool WinWindow::IsVSync() const { return m_Data.VSync; }

}  // namespace Aurora
