#include "./Adafruit_NeoPixel.h"
#include "./EasyButton.h"

#define LED_PIN 1
#define BUTTON_PIN 2
#define LIGHT_STRIP_PIN 1
#define LIGHT_STRIP_LED_COUNT 10

#define MODE_COUNT 5
#define OFF_MODE -1

// --------------------------------------------------------------------------------

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LIGHT_STRIP_LED_COUNT, LIGHT_STRIP_PIN, NEO_GRB + NEO_KHZ800);

const uint32_t seaHawksGreen = strip.Color(50, 255, 5);
const uint32_t seaHawksBlue = strip.Color(0, 22, 63);

// --------------------------------------------------------------------------------

void (*startFunctions[])() = {colorWipeSetup, theaterChaseDuoSetup, waveSetup, runningLightsSetup, skittleSetup};
void (*loopFunctions[])() = {colorWipeDrawFrame, theaterChaseDuoDrawFrame, waveDrawFrame, runningLightsDrawFrame, skittleDrawFrame};

// --------------------------------------------------------------------------------

EasyButton button(BUTTON_PIN);
//EasyButton button(BUTTON_PIN, buttonPush, CALL_IN_PUSHED, true);
//EasyButton button2(BUTTON_PIN, stripToggle, CALL_IN_HOLD, true);

void setup() {
  //pinMode(LED_PIN, OUTPUT);
  //digitalWrite(LED_PIN, HIGH);

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  colorWipe(strip.Color(32, 32, 32), 25);
}

int currentLoop = OFF_MODE;
int stripOn = true;

void loop() {
  // this saves calls to millis()
  //unsigned long myMillis = millis();
  /*button.update(myMillis);
  button2.update(myMillis);
  
  if(currentLoop != OFF_MODE)
  {
    void(*loopFunc)()  = loopFunctions[currentLoop];
    if(loopFunc)
    {
      loopFunc();
    }
  }*/  
}

void stripToggle()
{
  if(stripOn)
  {
    for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, 0);
    }
    strip.show();
    stripOn = false;
  } else {
    stripOn = true;
    currentLoop = 0;
    startCurrentMode();
  }
}

void buttonPush()
{
  if(stripOn)
  {
    currentLoop = (currentLoop + 1) % MODE_COUNT;
    startCurrentMode();
  }
}

void startCurrentMode()
{
  void (*setupFunc)() = startFunctions[currentLoop];
  if(setupFunc)
  {
    setupFunc();
  }
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
