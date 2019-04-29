#ifndef KEY_H
#define KEY_H

class Key {
public:
  bool pressed;
  bool clicked;
  
  Key();
  
  void press();
  void release();
};

#endif