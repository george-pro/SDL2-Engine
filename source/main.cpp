#include "Game.h"
#include <windows.h>

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
  ::ShowWindow(::GetConsoleWindow(), SW_HIDE);
  Game().run();
  return 0;
}
