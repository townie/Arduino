//#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
//#include "printf.h"
const short int relay = 4;
const short int ce = 2;
const short int csn = 3;
//
// Hardware conf
//
 
// Set up nRF24L01 radio on SPI bus plus pins 9 & 10 
 
RF24 radio(ce,csn);
 
//
// Topology
//
 
// Radio pipe addresses for the 2 nodes to communicate.
const uint64_t pipes[2] = { 0xF0F0F0F0E1LL, 0xF0F0F0F0D2LL };
 
void setup(void)
{
  //
  // Print preamble
  //
 
//  Serial.begin(9600);
//  Serial.write("Radio Active");
//  printf("\nLight Switch Arduino\n\r");
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);
//  Serial.write("Radio Active");
//  printf_begin();
//  printf("\nLight Switch Arduino\n\r");
// 
  //
  // Setup and configure rf radio
  //
 
  radio.begin();
  radio.setRetries(15,15);
 
  radio.openWritingPipe(pipes[0]);
  radio.openReadingPipe(1,pipes[1]);
  radio.startListening();
//  radio.printDetails();
}
 
void loop(void)
{
//    Serial.write("Radio Active");

 
    // if there is data ready
    if ( radio.available() )
    {
//      Serial.write("Radio Active");
      // Dump the payloads until we've gotten everything
      unsigned short message;
      bool done = false;
      while (!done)
      {
        // Fetch the payload, and see if this was the last one.
        done = radio.read( &message, sizeof(unsigned long) );
 
        // Spew it
        // printf("Got message %lu...",message);
        if (message == 1){
          digitalWrite(relay, LOW);
        }else{
          digitalWrite(relay, HIGH);
        }
 
    // Delay just a little bit to let the other unit
    // make the transition to receiver
    delay(20);
      }
 
      // First, stop listening so we can talk
      radio.stopListening();
 
      // Send the final one back.
      radio.write( &message, sizeof(unsigned long) );
//      printf("Sent response.\n\r");
 
      // Now, resume listening so we catch the next packets.
      radio.startListening();
    }
}
