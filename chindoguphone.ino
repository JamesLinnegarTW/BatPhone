#include "Pulse.h"

const int pulsePin = 2;
const int dialingPin = 3;

int ledState = HIGH;
int lastButtonState = 0;
int buttonCount = 0;
bool outputNumber = false;
Pulse dialPulse = Pulse();


void setup() {
  // put your setup code here, to run once:
  dialPulse.init(10);
  pinMode(pulsePin, INPUT);
  pinMode(dialingPin, INPUT);

  while (!Serial); // wait for serial
  Serial.begin(115200);
  Serial.println(F("Initializing....Phone"));
}

void loop() {

  int pulse = digitalRead(pulsePin);

  int dialing = digitalRead(dialingPin);

  incrementIfChanged(pulse);
  if(isPressed(dialing)) {
    if(!outputNumber){
      if(buttonCount == 10){
        buttonCount = 0;
      }
        
      Serial.print(buttonCount);
      buttonCount = 0;
      outputNumber = true;
      
    }
  } else {
    outputNumber = false;
  }
  delay(30);
}

void incrementIfChanged(int currentState) {
  int lastState = lastButtonState;
  
  if(lastState != currentState) {
    if(currentState == LOW){
      buttonCount++;
    }
    
    lastButtonState = currentState;
  }
}

bool isPressed(int currentState) {
  int lastState = lastButtonState;
  
  if(lastState != currentState) {
    if(currentState == LOW){
      return true;
    }
  }

  return false;
}
