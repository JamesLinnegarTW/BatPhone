#include "Pin.h"
#include "Arduino.h"

Pin::Pin(void){}

void Pin::init(int pinNumber){
  this->pinNumber = pinNumber;
  this->lastState = 0;
  this->lastStateChangeTime = 0;
  this->debounceDelay = 10;
  this->trueState = 0;
  pinMode(pinNumber, INPUT);
}

void Pin::incrementIfChanged(int reading) {

  if(reading != this->lastState) {
    this->lastStateChangeTime = millis();
  } 
  
  if((millis() - this->lastStateChangeTime) > this->debounceDelay){
    //debounce - this happens once it's stable
    if(reading != this->trueState) {
      //this means the switch has either gone from closed/open or reverse
      this->trueState = reading;
      
      if(this->trueState == LOW){
        this->pressCount++;
      }
      
    }
   
  }
  this->lastState = reading;
}


void Pin::sample() {
  int reading = digitalRead(this->pinNumber);
  incrementIfChanged(reading);
}

int Pin::count() {
  return this->pressCount;
}

int Pin::getState() {
  return this->trueState;
}

void Pin::reset() {
  this->pressCount = 0;
}

