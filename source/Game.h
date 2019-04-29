#ifndef GAME_H
#define GAME_H

#include "Application.h"
#include "Keyboard.h"
#include "Sprite.h"

class Game : public Application {
public:
  Keyboard* keyboard;
  Sprite* block;
  int x;
  int y;
  
  Game();
  
  void handleInput(SDL_Event event);
  void update();
  void render(double lag);

  ~Game();
};

#endif