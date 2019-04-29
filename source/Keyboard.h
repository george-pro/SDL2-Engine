#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "Key.h"
#include <SDL2/SDL.h>
#include <map>

class Keyboard {
public:
  std::map<int, Key*> map_of_keys;
  
  Keyboard(int* keycode_array);
  
  Key* getKey(int keycode);
  void handleInput(SDL_Event event);
  bool extractStatus(int keycode);
};

#endif