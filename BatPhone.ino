#include "Pin.h"

const int pulsePin = 2;
const int dialingPin = 3;

int ledState = HIGH;
int lastButtonState = 0;
bool numberDialled = false;
Pin dialPulse = Pin();
char phoneNumber[11];

void setup() {
  // put your setup code here, to run once:
  
  dialPulse.init(pulsePin);
  
  pinMode(dialingPin, INPUT);

  while (!Serial); // wait for serial
  Serial.begin(115200);
  Serial.println(F("Initializing....Phone"));
}

void loop() {
  dialPulse.sample();
  waitForDial(handleDialled);
  delay(10);
}

void handleDialled() {
  int digit = countToDigit(dialPulse.count());
  phoneNumber[0] = (char) digit;
  Serial.print(digit);    
  dialPulse.reset();
}

int countToDigit(int count) {
  if (count > 9){
    return 0;
  }
  return count;  
}

void waitForDial(void (*onDialled)(void)) {
  int dialing = digitalRead(dialingPin);
  
  if(isPressed(dialing)) {
    if(!numberDialled){
      onDialled();
      numberDialled = true;
    }
  } else {
    numberDialled = false;
  }
  
  lastButtonState = dialing;  
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
