const redPin = 0;
const greenPin = 1;
const bluePin = 4;
#include <RGBMood.h>
RGBMood m(redPin, greenPin, bluePin);

void setup() {
  m.setMode(RGBMood::FIRE_MODE); // Fire effect
}

void loop() {
  m.tick(); // Update the colors.
}
