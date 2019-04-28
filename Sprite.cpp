#include "Sprite.h"
#include <SDL2/SDL.h>

Sprite::Sprite(const char* path) {
  image = SDL_LoadBMP(path);
}

void Sprite::render(SDL_Surface* canvas, int x, int y) {
  SDL_Rect rect = {x, y, image->w, image->h};
  SDL_BlitSurface(image, NULL, canvas, &rect);
}

Sprite::~Sprite() {
  SDL_FreeSurface(image);
}
