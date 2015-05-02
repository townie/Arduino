#include <LED.h>

//int red = 12;
//int green = 2;
int lightSensor = A0;

int LEDArray[] = {11,10,9}; // Red, Green, Blue
LED LED1(LEDArray);

void setup() {                
//  pinMode(red, OUTPUT);
//  pinMode(green, OUTPUT); 
  pinMode(lightSensor, INPUT);  
  Serial.begin(9600);
}

void loop() {


  
  int lightDensity = analogRead(lightSensor);
  delay(1000);
  Serial.println(lightDensity);
 

  byte start[] = {0, 0, 0};
  byte red[] = {255, 0, 255};
  byte blue[]={13,12,232};
  byte green[]={13,255,131};
  byte white[]={255,255,255};

  if (lightDensity >= 400) {
  LED1.Fade(LEDArray, blue, blue, 3); 

    //digitalWrite(red, HIGH);
    //digitalWrite(green, LOW);
  }
  else {
    //digitalWrite(green, HIGH);
    //digitalWrite(red, LOW);
    LED1.Fade(LEDArray, blue , green, 0); // 1

  }
}


