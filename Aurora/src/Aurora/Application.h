#pragma once
#include "Core.h"
namespace Aurora {
class AUR_API Application {
 public:
  Application();
  virtual ~Application();
  void Run();
};

Application* CreateApplication();

}  // namespace Aurora
