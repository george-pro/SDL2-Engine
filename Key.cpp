#include "Key.h"

Key::Key() {
  pressed = false;
}

void Key::press() {
  pressed = true;
}

void Key::release() {
  pressed = false;
}

bool Key::isPressed() {
	return pressed;
}
