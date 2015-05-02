// Motion Sensor Light Code
// Keith Webber

int ledPin = 13; // choose the pin for the LED
int inputPin = 2; // choose the input pin (for PIR sensor)
int pirState = LOW; // we start, assuming no motion detected
int val = 0; // variable for reading the pin status
int lTimer = 0;
const int redPin = 0;
const int greenPin = 1;
const int bluePin = 3;
 
 
void setup() {
  pinMode(ledPin, OUTPUT); // declare LED as output
  pinMode(inputPin, INPUT); // declare sensor as input
  lTimer = 500;
//  Serial.begin(9600);
  setColourRgb(0,0,0);
}

void loop(){
  val = digitalRead(inputPin); // read input value
  if (val == HIGH) { // check if the input is HIGH
//    digitalWrite(ledPin, LOW ); // turn LED OFF
    if (pirState == LOW) 
      {
      // we have just turned on
//      Serial.println("Motion detected!");
      // We only want to print on the output change, not state
      pirState = HIGH;
     }
    } else
    {
      colorMagic();
     // digitalWrite(ledPin, HIGH); // turn LED ON
      if (pirState == HIGH)
      {
        // we have just turned of
//        Serial.println("Motion ended!");
        // We only want to print on the output change, not state
        pirState = LOW;

      }
  }
}

int incLight(int amt) {
  lTimer = lTimer + amt;
  return lTimer;
}



void colorMagic() {
  unsigned int rgbColour[3];
 
  // Start off with red.
  rgbColour[0] = 255;
  rgbColour[1] = 0;
  rgbColour[2] = 0;  
 
  // Choose the colours to increment and decrement.
  for (int decColour = 0; decColour < 3; decColour += 1) {
    int incColour = decColour == 2 ? 0 : decColour + 1;
 
    // cross-fade the two colours.
    for(int i = 0; i < 255; i += 1) {
      rgbColour[decColour] -= 1;
      rgbColour[incColour] += 1;
      
      setColourRgb(rgbColour[0], rgbColour[1], rgbColour[2]);
      delay(50 );
    }
  }
}
 
void setColourRgb(unsigned int red, unsigned int green, unsigned int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
 }
