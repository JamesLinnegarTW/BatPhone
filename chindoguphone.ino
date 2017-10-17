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
  dialPulse.init(pulsePin);
  
  pinMode(dialingPin, INPUT);

  while (!Serial); // wait for serial
  Serial.begin(115200);
  Serial.println(F("Initializing....Phone"));
}

void loop() {

  int dialing = digitalRead(dialingPin);

  dialPulse.sample();
  //Serial.print(dialPulse.count());
  if(isPressed(dialing)) {
    if(!outputNumber){
      int count = dialPulse.count();
      if(count > 9){
        count = 0;
      }
      Serial.print(count);
      buttonCount = 0;
      outputNumber = true;
      dialPulse.reset();
      
    }
  } else {
    outputNumber = false;
  }
  lastButtonState = dialing;
  delay(30);
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
