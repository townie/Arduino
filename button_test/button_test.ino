
// this is a test for the non pull-down and non debounce led
// written for the arduino micro

int led = 12;
int two = 11;

void setup(){
  pinMode(led, OUTPUT);
  
}

void loop(){
    analogWrite(two, 255);
    digitalWrite(led, HIGH);

  
} 
