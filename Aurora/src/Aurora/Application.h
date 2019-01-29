#pragma once
#include "Core.h"
#include "Aurora\Log.h"
#include "Events/Event.h"
#include "Events/AppEvent.h"
namespace Aurora {
class AUR_API Application {
 public:
  Application();
  virtual ~Application();
  void Run();
};

Application* CreateApplication();

}  // namespace Aurora
