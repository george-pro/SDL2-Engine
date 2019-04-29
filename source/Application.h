#ifndef APPLICATION_H
#define APPLICATION_H

#include <SDL2/SDL.h>

class Application {
public:
  SDL_Window* window;
  SDL_Surface* canvas;
  int ms_per_update;
  
  Application(const char* title, int width, int height, int updates_per_second);
  
  virtual void handleInput(SDL_Event event);
  virtual void update();
  virtual void render(double lag);
  
  void run();
  
  ~Application();
};

#endif