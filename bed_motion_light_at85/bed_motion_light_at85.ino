/*
  Blink
 Turns on an LED on for one second, then off for one second, repeatedly.
 
 This example code is in the public domain.
 */

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 3;
int sensor = 4;
int buttonState = 0;
int button = 0;
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);  
  pinMode(sensor, INPUT);
  pinMode(button, INPUT);
 }

// the loop routine runs over and over again forever:
void loop() {
  if (buttonState == 1)
  {
    lightOn();
  }
  else if (digitalRead(sensor) == HIGH) {
    lightOn();
  }
  buttonState = digitalRead(button);
  lightOff();
}

void lightOn() {
    digitalWrite(led, HIGH );   // turn the LED on (HIGH is the voltage level)
    delay(500000);               // wait for a second
}

void lightOff() {
  digitalWrite(led, LOW);  
  delay(10);
}

