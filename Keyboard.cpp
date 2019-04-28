#include "Keyboard.h"
#include "Key.h"
#include <SDL2/SDL.h>

Keyboard::Keyboard(int* keycode_array) {
  for (int i = 0; i < sizeof(keycode_array); i++) {
    map_of_keys[keycode_array[i]] = new Key();
  }
}

Key* Keyboard::getKey(int keycode) {
  return map_of_keys[keycode];
}

void Keyboard::handleInput(SDL_Event event) {
  Key* key = getKey(event.key.keysym.sym);
  
  if (key != NULL) {
    if (event.type == SDL_KEYDOWN) {
      key->press();
    } else if (event.type == SDL_KEYUP) {
      key->release();
    }
  }
}
