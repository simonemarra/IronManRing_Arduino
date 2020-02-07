#include <Adafruit_NeoPixel.h>

#define RING_PIN    2//6
// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 36//16//60
Adafruit_NeoPixel strip(LED_COUNT, RING_PIN, NEO_GRB + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)

int16_t blueVal = 0;
#define BLUE_MIN  105
#define RED_MIN   15
#define GREEN_MIN 15
#define BRIGHTNESS_DEFAULT  125//50

void setup() 
{
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(BRIGHTNESS_DEFAULT); // Set BRIGHTNESS to about 1/5 (max = 255)
  /*
  for(int b = 0; b < 10; b++)
  {
    colorWipe(strip.Color(RED_MIN, GREEN_MIN, 255), 5); // Blue
    colorWipe(strip.Color(RED_MIN, GREEN_MIN, BLUE_MIN), 5); // Blue
  }
  */
}

void loop() 
{
  // put your main code here, to run repeatedly:
  for(blueVal = BLUE_MIN; blueVal <= 255; blueVal+=10)
  {
    colorWipe(strip.Color(RED_MIN, GREEN_MIN, (uint8_t)blueVal),0);
  }
  for(blueVal = 255; blueVal >= BLUE_MIN; blueVal-=10)
  {
    colorWipe(strip.Color(RED_MIN, GREEN_MIN, (uint8_t)blueVal),0);
  }

}

void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}
