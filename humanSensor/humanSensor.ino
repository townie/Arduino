int human = 2;

void setup()
{
  pinMode(human, INPUT);  
  Serial.begin(9600);
}  

void loop()
{
    Serial.println(digitalRead(human));
    delay(1000);
}
