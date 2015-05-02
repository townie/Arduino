
void setup(){
 pinMode(13,OUTPUT);
 pinMode(2,INPUT);
}

void loop(){
 digitalWrite(13,digitalRead(2));
}
