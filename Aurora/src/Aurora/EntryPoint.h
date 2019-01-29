#pragma once
#include "Application.h"
#ifdef AUR_PLATFORM_WINDOWS

extern Aurora::Application* Aurora::CreateApplication();

int main(int argc, char** argv) {
  Aurora::Log::Init();
  AUR_CORE_WARN("Initialized Log!");

  int c = 1 <<2 ;
  AUR_CORE_INFO(c);
  auto app = Aurora::CreateApplication();
  app->Run();
  delete app;
  return 0;
}

#endif
