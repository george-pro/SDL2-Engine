#include "Game.h"
#include "Application.h"
#include "Keyboard.h"
#include "Sprite.h"
#include <iostream>

const char* WINDOW_TITLE = "My Game";
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
const int UPDATES_PER_SEC = 120;

Game::Game() : Application(WINDOW_TITLE, SCREEN_WIDTH, SCREEN_HEIGHT, UPDATES_PER_SEC) {
  int keys[] = {SDLK_UP, SDLK_DOWN, SDLK_LEFT, SDLK_RIGHT};
  keyboard = new Keyboard(keys);
  block = new Sprite("image/block.bmp");
  x = (SCREEN_WIDTH - 64) / 2;
  y = (SCREEN_HEIGHT - 64) / 2;
}

void Game::handleInput(SDL_Event event) {
  keyboard->handleInput(event);
}

void Game::update() {
  bool up = keyboard->extractStatus(SDLK_UP);
  bool down = keyboard->extractStatus(SDLK_DOWN);
  bool left = keyboard->extractStatus(SDLK_LEFT);
  bool right = keyboard->extractStatus(SDLK_RIGHT);
  
  if (up) y -= 1;
  if (down) y += 1;
  if (left) x -= 1;
  if (right) x += 1;
}

void Game::render(double lag) {
  SDL_FillRect(canvas, NULL, SDL_MapRGB(canvas->format, 0x0, 0x0, 0xFF));
  block->render(canvas, x, y);
}

Game::~Game() {
}
