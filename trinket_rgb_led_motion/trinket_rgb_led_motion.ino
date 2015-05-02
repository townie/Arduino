/*

*/
int i = 0;
int redPin = 0;
int greenPin = 1;
int bluePin = 3;
int sensor = 2;


void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(sensor,INPUT);
}

void loop()
{
//    setColor(digitalRead(sensor),0,  0); 
//    delay(1000);

  int sensorReading = digitalRead(sensor);
  
  if (sensorReading >= 100) 
  { // set to blue cuz its cool
    setColor(0, 0, 255);  
  } 
  else if (sensorReading >= 200 )
  {// set to green 
    setColor(0, 255, 0);
  }
  else if (sensorReading >= 300 )
  { // to red
     setColor(255, 0, 0);
  }
  else
  { // default to white
     setColor(255, 255, 255);
  }

}

void setColor(int red, int green, int blue)
{
  
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}


void breathLeds(float red, float green, float blue)
{
  for(i = 15 ; i <= 255; i+=1)
  { 
    setColor(int(red * i), int(green * i), int(blue * i));
    
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
    setColor(int(red * i), int(green * i), int(blue * i));
//    String stringOne = "red value: ";
//    String stringThree = stringOne + int(red);
//    Serial.println(stringThree);    
   
    if (i > 150) 
    {
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
  delay(90);
}
