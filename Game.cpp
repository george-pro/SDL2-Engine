#include "Game.h"
#include "Application.h"
#include "Keyboard.h"
#include "Sprite.h"
#include <iostream>

Game::Game(const char* title, int width, int height) : Application(title, width, height) {
  int keys[] = {SDLK_UP, SDLK_DOWN, SDLK_LEFT, SDLK_RIGHT};
  keyboard = new Keyboard(keys);
  block = new Sprite("image/block.bmp");
  x = (640 - 64) / 2;
  y = (480 - 64) / 2;
}

void Game::handleInput(SDL_Event event) {
  keyboard->handleInput(event);
}

void Game::update() {
  bool up = keyboard->getKey(SDLK_UP)->isPressed();
  bool down = keyboard->getKey(SDLK_DOWN)->isPressed();
  bool left = keyboard->getKey(SDLK_LEFT)->isPressed();
  bool right = keyboard->getKey(SDLK_RIGHT)->isPressed();
  
  if (up && not down) {
    y = ((480 - 64) / 2) - 64;
  } else if (down && not up) {
    y = ((480 - 64) / 2) + 64;
  } else {
    y = (480 - 64) / 2;
  }

  if (left && not right) {
    x = ((640 - 64) / 2) - 64;
  } else if (right && not left) {
    x = ((640 - 64) / 2) + 64;
  } else {
    x = (640 - 64) / 2;
  }
}

void Game::render(double lag) {
  SDL_FillRect(canvas, NULL, SDL_MapRGB(canvas->format, 0x0, 0x0, 0xFF));
  block->render(canvas, x, y);
}

Game::~Game() {
}
