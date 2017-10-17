#ifndef PIN_H
#define PIN_H

#include "Arduino.h"

class Pin {
 public:
  Pin(void);
  void init(int pinNumber);
  void sample();
  int count();
  void reset();
  
 private:
  int pinNumber;
  int lastState;
  int pressCount;
  void incrementIfChanged(int currentState);
};
#endif
