#include "Application.h"
#include <iostream>

class Game : public Application {
public:
  SDL_Surface* image;
  SDL_Rect rect;
  
  Game(const char* title, int width, int height) : Application(title, width, height) {
    image = SDL_LoadBMP("image/block.bmp");
    rect.x = 0;
    rect.y = 0;
    rect.w = 64;
    rect.h = 64;
  }
  
  void handleInput(SDL_Event event) {
    if (event.type == SDL_KEYDOWN) {
      switch(event.key.keysym.sym) {
        case SDLK_UP:
          rect.y -= 5;
          break;
        case SDLK_DOWN:
          rect.y += 5;
          break;
        case SDLK_LEFT:
          rect.x -= 5;
          break;
        case SDLK_RIGHT:
          rect.x += 5;
          break;
      }
    }
  }
  
  void update() {
    // updates...
  }
  
  void render(double lag) {
    // render... (passing in lag as a ratio for extrapolating current mid-update position)
    SDL_FillRect(canvas, NULL, SDL_MapRGB(canvas->format, 0x0, 0x0, 0xFF));
    SDL_BlitSurface(image, NULL, canvas, &rect);
  }

  ~Game() {
    SDL_FreeSurface(image);
  }
};

int main(int argc, char* args[]) {
  Game app = Game("My Game", 640, 480);
  app.run();
  return 0;
}
