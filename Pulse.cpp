#include "Pulse.h"
#include "Arduino.h"

Pulse::Pulse(void){}

void Pulse::init(int pinNumber){
  this->pinNumber = pinNumber;
  this->lastState = 0;
  pinMode(pinNumber, INPUT);
}

void Pulse::incrementIfChanged(int currentState) {
  if(this->lastState != currentState) {
    if(currentState == LOW){
      this->pressCount++;
    }
    
    this->lastState = currentState;
  }
}


void Pulse::sample() {
  int reading = digitalRead(this->pinNumber);
  incrementIfChanged(reading);
}


int Pulse::count() {
  return this->pressCount;
}

void Pulse::reset() {
  this->pressCount = 0;
}

