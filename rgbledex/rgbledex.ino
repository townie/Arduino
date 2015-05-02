/*
Adafruit Arduino - Lesson 3. RGB LED
*/

int redPin = 11;
int greenPin = 10;
int bluePin = 9;
int lightSensor = A0;

void setup()
{
  pinMode(lightSensor, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
   Serial.begin(9600);
}

void loop()
{
  int lightDensity = analogRead(lightSensor);
  
  Serial.println(lightDensity);
  
  if (lightDensity >= 400) {
    setColor(0, 255, 0);  // red
    delay(1000);
  }
  else {
    setColor(255, 0, 0);  // green
    delay(1000);
  }
}

void setColor(int red, int green, int blue)
{
  
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
