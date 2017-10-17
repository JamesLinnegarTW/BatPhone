#ifndef PULSE_H
#define PULSE_H

#include "Arduino.h"

class Pulse {
 public:
  Pulse(void);
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
