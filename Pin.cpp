#include "Pin.h"
#include "Arduino.h"

Pin::Pin(void){}

void Pin::init(int pinNumber){
  this->pinNumber = pinNumber;
  this->lastState = 0;
  pinMode(pinNumber, INPUT);
}

void Pin::incrementIfChanged(int currentState) {
  if(this->lastState != currentState) {
    if(currentState == LOW){
      this->pressCount++;
    }
    
    this->lastState = currentState;
  }
}


void Pin::sample() {
  int reading = digitalRead(this->pinNumber);
  incrementIfChanged(reading);
}


int Pin::count() {
  return this->pressCount;
}

void Pin::reset() {
  this->pressCount = 0;
}

