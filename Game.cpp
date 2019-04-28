#include "Game.h"
#include "Application.h"
#include "Sprite.h"
#include <iostream>

Game::Game(const char* title, int width, int height) : Application(title, width, height) {
  block = new Sprite("image/block.bmp");
  
  x = (640 - 64) / 2;
  y = (480 - 64) / 2;
  
  up_pressed = false;
  down_pressed = false;
  left_pressed = false;
  right_pressed = false;
}

void Game::handleInput(SDL_Event event) {
  if (event.type == SDL_KEYDOWN) {
    switch(event.key.keysym.sym) {
      case SDLK_UP:
        up_pressed = true;
        break;
      case SDLK_DOWN:
        down_pressed = true;
        break;
      case SDLK_LEFT:
        left_pressed = true;
        break;
      case SDLK_RIGHT:
        right_pressed = true;
        break;
    }
  } else if (event.type == SDL_KEYUP) {
    switch(event.key.keysym.sym) {
      case SDLK_UP:
        up_pressed = false;
        break;
      case SDLK_DOWN:
        down_pressed = false;
        break;
      case SDLK_LEFT:
        left_pressed = false;
        break;
      case SDLK_RIGHT:
        right_pressed = false;
        break;
    }
  }
}

void Game::update() {
  if (up_pressed && not down_pressed) {
    y = ((480 - 64) / 2) - 64;
  } else if (down_pressed && not up_pressed) {
    y = ((480 - 64) / 2) + 64;
  } else {
    y = (480 - 64) / 2;
  }

  if (left_pressed && not right_pressed) {
    x = ((640 - 64) / 2) - 64;
  } else if (right_pressed && not left_pressed) {
    x = ((640 - 64) / 2) + 64;
  } else {
    x = (640 - 64) / 2;
  }
}

void Game::render(double lag) {
  // Fill Background
  SDL_FillRect(canvas, NULL, SDL_MapRGB(canvas->format, 0x0, 0x0, 0xFF));
  
  // Render Sprites
  block->render(canvas, x, y);
}

Game::~Game() {
}
