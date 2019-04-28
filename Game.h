#ifndef GAME_H
#define GAME_H

#include "Application.h"
#include "Sprite.h"

class Game : public Application {
public:
  Sprite* block;
  
  int x;
  int y;
  
  bool up_pressed;
  bool down_pressed;
  bool left_pressed;
  bool right_pressed;
  
  Game(const char* title, int width, int height);
  
  void handleInput(SDL_Event event);
  void update();
  void render(double lag);

  ~Game();
};

#endif