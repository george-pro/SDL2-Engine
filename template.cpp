#include "Application.h"

class Game : public Application {
public:
  Game(const char* title, int width, int height) : Application(title, width, height) {
    // Constructor...
  }
  
  void handleInput(SDL_Event event) {
    // input handling...
  }
  
  void update() {
    // updates...
  }
  
  void render(double lag) {
    // render... (passing in lag as a ratio for extrapolating current mid-update position)
  }

  ~Game() {
    // Destructor...
  }
};

int main(int argc, char* args[]) {
  Game app = Game("My Game", 640, 480);
  app.run();
  return 0;
}
