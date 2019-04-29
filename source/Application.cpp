#include "Application.h"
#include <SDL2/SDL.h>
#include <time.h>

Application::Application(const char* title, int width, int height, int updates_per_second) {
  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
  canvas = SDL_GetWindowSurface(window);
  ms_per_update = 1000 / updates_per_second;
}

void Application::handleInput(SDL_Event event) {
  // input handling...
}
  
void Application::update() {
  // updates...
}

void Application::render(double lag) {
  // render... (passing in lag as a ratio for extrapolating current mid-update position)
}

void Application::run() {
  bool running = true;
  clock_t previous_time = clock();
  // LOOP
  while (running) {
    // HANDLE INPUT
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        running = false;
      } else {
        handleInput(event);
      }
    }
    // UPDATE
    clock_t current_time = clock();
    clock_t elapsed_time = current_time - previous_time;
    for (int update_iterations = elapsed_time / ms_per_update; update_iterations > 0; update_iterations--) {
      update();
      previous_time += ms_per_update;
    }
    // RENDER
    double lag = current_time - previous_time;
    double lag_ratio = lag / ms_per_update;
    render(lag_ratio);
    SDL_UpdateWindowSurface(window);
  }
}

Application::~Application() {
  SDL_FreeSurface(canvas);
  SDL_DestroyWindow(window);
  SDL_Quit();
}
