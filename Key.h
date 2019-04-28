#ifndef KEY_H
#define KEY_H

class Key {
public:
  bool pressed;
  
  Key();
  
  void press();
  void release();
  bool isPressed();
};

#endif