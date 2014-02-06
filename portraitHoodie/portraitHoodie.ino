#include "./Adafruit_NeoPixel.h"
#include "./ToggleButton.h"

#define LED_PIN 1
#define BUTTON_PIN 0
#define LIGHT_STRIP_PIN 1
#define LIGHT_STRIP_LED_COUNT 97

#define MODE_COUNT 5
#define INIT_MODE -1


#define SEAHAWKS_GREEN strip.Color(50, 255, 5)
#define SEAHAWKS_BLUE strip.Color(0, 22, 63)

// --------------------------------------------------------------------------------

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LIGHT_STRIP_LED_COUNT, LIGHT_STRIP_PIN, NEO_GRB + NEO_KHZ800);

// --------------------------------------------------------------------------------


// --------------------------------------------------------------------------------

ToggleButton button(BUTTON_PIN, buttonPush, buttonHold);

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  colorWipe(strip.Color(32, 32, 32), 25);
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
        //colorWipe(strip.Color(64, 64, 64), 25);
        break;
      case 1:
        //colorWipe(strip.Color(100, 100, 25), 25);
        break;    
      case 2:
        //colorWipe(strip.Color(76, 0, 153), 25);
        break;
      case 3:
        //colorWipe(strip.Color(127, 0, 255), 25);
        break;
      case 4:
        //waveDrawFrame();
        break;
    }
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
      colorWipe(strip.Color(64, 64, 64), 25);
      break;
    case 1:
     colorWipe(strip.Color(76, 0, 153), 25);
      break;
    case 2:
     colorWipe(strip.Color(127, 0, 255), 25);
      break;
    case 3:
      colorWipe(strip.Color(100, 100, 25), 25);
      break;
    case 4:
     colorWipe(strip.Color(150, 150, 75), 25);
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


// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait)
{
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}
