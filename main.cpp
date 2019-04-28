#include "Game.h"

int main(int argc, char* args[]) {
  Game app = Game("My Game", 640, 480);
  app.run();
  return 0;
}
