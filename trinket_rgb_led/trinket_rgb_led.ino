/*

*/

int redPin = 5;
int greenPin = 6;
int bluePin = 7;


void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop()
{


    setColor(0, 255, 0);  // red
    delay(1000);

    setColor(255, 0, 0);  // green
    delay(1000);
    
    setColor(0, 0, 255);  //blue
    delay(1000);

}

void setColor(int red, int green, int blue)
{
  
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
