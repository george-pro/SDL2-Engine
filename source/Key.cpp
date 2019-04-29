#include "Key.h"

Key::Key() {
  pressed = false;
  clicked = false;
}

void Key::press() {
  pressed = true;
}

void Key::release() {
  pressed = false;
  clicked = true;
}