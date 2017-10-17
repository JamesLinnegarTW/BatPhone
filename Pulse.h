#ifndef PULSE_H
#define PULSE_H

#include "Arduino.h"

class Pulse {
 public:
  Pulse(void);
  void init(int pinNumber);
  
 private:
  int pinNumber;
};
#endif
