const int buttonPin = 2;
const int ledPin = 13;

int ledState = HIGH;
int lastButtonState = 0;

void setup() {
  // put your setup code here, to run once:

  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  while (!Serial); // wait for serial
  Serial.begin(115200);
  Serial.println(F("Initializing....Phone"));
}

void loop() {

  int reading = digitalRead(buttonPin);

  digitalWrite(ledPin, reading);
  if(lastButtonState != reading) {
    Serial.println(reading);
    lastButtonState = reading;
  }
}
