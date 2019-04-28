#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>

class Sprite {
public:
  SDL_Surface* image;
  
  Sprite(const char* path);
  
  void render(SDL_Surface* canvas, int x, int y);
  
  ~Sprite();
};

#endif