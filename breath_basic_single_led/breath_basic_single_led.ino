/*
"Breathing sleep LED, like on a Mac.
Jeremy Saglimbeni 2011
thecustomgeek.com

LED is attached to pin 11 in series with a 5.6K resistor
*/
int i = 0;

int redPin = 11;
int greenPin = 10;
int bluePin = 9;
int lightSensor = A0;
void setup() { // bring the LED up nicely from being off
  pinMode(lightSensor, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  for(i = 0 ; i <= 15; i+=1)
  {
    analogWrite(11, i);
    delay(5);
  }
  
}
void loop()
{
  if (analogRead(lightSensor) >= 375)
  {
    
    breathLoop(1,0,0);
  }
  else
  {
       breathLoop(0,0,1);

  }
  
}

void setColor(int red, int green, int blue)
{
  
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

void breathLoop(int red, int green, int blue)
{
  for(i = 15 ; i <= 255; i+=1)
  { 
    setColor((i * red), (0 * green), (i * blue));
    if (i > 150) {
      delay(4);
    }
    if ((i > 125) && (i < 151)) {
      delay(5);
    }
    if (( i > 100) && (i < 126)) {
      delay(7);
    }
    if (( i > 75) && (i < 101)) {
      delay(10);
    }
    if (( i > 50) && (i < 76)) {
      delay(14);
    }
    if (( i > 25) && (i < 51)) {
      delay(18);
    }
    if (( i > 1) && (i < 26)) {
      delay(19);
    }
  }
  for(i = 255; i >=15; i-=1)
  {
    setColor((i * red), (0 * green), (i * blue));
    if (i > 150) {
      delay(4);
    }
    if ((i > 125) && (i < 151)) {
      delay(5);
    }
    if (( i > 100) && (i < 126)) {
      delay(7);
    }
    if (( i > 75) && (i < 101)) {
      delay(10);
    }
    if (( i > 50) && (i < 76)) {
      delay(14);
    }
    if (( i > 25) && (i < 51)) {
      delay(18);
    }
    if (( i > 1) && (i < 26)) {
      delay(19);
    }
  }
  delay(970);
}
