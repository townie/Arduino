#include "rgb.h"

// Red is on pin 11, green on 10 and blue on 9.
// These are all PWM pins. Initial color is black (off).
struct RGBLED led = {11, 10, 9, RGB_BLACK};

void setup() {
	pinMode(led.pinRed, OUTPUT);
	pinMode(led.pinGreen, OUTPUT);
	pinMode(led.pinBlue, OUTPUT);

	setRgbLed(led);

	// This assumes nothing is connected to analog 1.
	randomSeed(analogRead(1));
}

void loop() {
/*
 * This makes the LED fade nicely from red, through green to
 * blue and back to red, hitting all the colors in between.
 *
	fadeRgbLed(&led, RGB_RED);
	fadeRgbLed(&led, RGB_GREEN);
	fadeRgbLed(&led, RGB_BLUE);
*/

/*
 * This rades from random color to random color.
 */
	RGB color = { led.color.g, led.color.b, random(256) };
	fadeRgbLed(&led, color);
/**/
}
