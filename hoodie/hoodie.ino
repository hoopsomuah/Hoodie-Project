#include "./Adafruit_NeoPixel.h"
#include "./ToggleButton.h"

#define LED_PIN 7
#define BUTTON_PIN 9
#define LIGHT_STRIP_PIN 10
#define LIGHT_STRIP_LED_COUNT 46

#define MODE_COUNT 2
#define INIT_MODE -1

// --------------------------------------------------------------------------------

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LIGHT_STRIP_LED_COUNT, LIGHT_STRIP_PIN, NEO_GRB + NEO_KHZ800);

const uint32_t seaHawksGreen = strip.Color(50, 255, 5);
const uint32_t seaHawksBlue = strip.Color(0, 22, 63);

// --------------------------------------------------------------------------------


// --------------------------------------------------------------------------------

ToggleButton button(BUTTON_PIN, buttonPush, buttonHold);

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  colorWipe(strip.Color(64, 64, 64), 25);
}

int currentLoop = INIT_MODE;
int stripOn = true;

void loop() {
  button.update();
  
  if(currentLoop != INIT_MODE && stripOn)
  {
    switch(currentLoop)
    {
      case 0:
        colorWipeDrawFrame();
        break;
      case 1:
      theaterChaseDuoDrawFrame();
        break;    
    }
}

void buttonPush(int count)
{
  if(stripOn)
  {
    currentLoop = (currentLoop + count) % MODE_COUNT;
    startCurrentMode();
  }
}

void startCurrentMode()
{
  switch(currentLoop)
  {
    case 0:
      colorWipeSetup();
      break;
    case 1:
      theaterChaseDuoSetup();
      break;
  }
}

void buttonHold() // Toggle
{
  if(stripOn)
  {
    // turn the strip off
    for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, 0);
    }
    strip.show();
    stripOn = false;
  } else {
    // turn the strip on
    stripOn = true;
    currentLoop = 0;
    startCurrentMode();
  }
}

void loopCurrentMode()
{

}


void allRed()
{
  colorWipe(strip.Color(255, 0, 0), 50);
}

void allBlue()
{
  colorWipe(strip.Color(0, 0, 255), 50);
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait)
{
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}
