/*
Pink: 255-105-180 - breathLeds(1.0, 0.41176470588, 0.70588235294);  

Green: 127-255-0 - 
*/


int i = 0;
int redPin = 11;
int greenPin = 10;
int bluePin = 9;
int lightSensor = A0;
int humanSensor = A1;

void setup()
{
  pinMode(lightSensor, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(humanSensor, INPUT);
  
  //  Wake the pins up casuauly 
  for(i = 0 ; i <= 255; i+=5)
  {
    setColor((i * 0.1), 0 , (i * 0.5));
    delay(66);
  }
  Serial.begin(9600);
}

void loop()
{
  int lightDensity = analogRead(lightSensor);
  
  Serial.println(lightDensity);
  Serial.println(analogRead(humanSensor));
  if (lightDensity >= 400) {
    breathLeds(0.0, 0.0, 0.70588235294);  

  }
  else {
   // breathLeds(0.1, 0.2, 0.5); 
   breathLeds(0.20, 0.41176470588, 0.70588235294); 

  }
}


int convertColor(int rgbColor) 
{
  return float ( rgbColor/255);
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
