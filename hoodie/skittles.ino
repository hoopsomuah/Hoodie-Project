

void skittleSetup()
{
  currPixel = 0;
}

void skittleDrawFrame()
{
  for(int i =0; i<LIGHT_STRIP_LED_COUNT; i++)
  {
    strip.setPixelColor(i, Wheel(((i * 256 / LIGHT_STRIP_LED_COUNT) + currPixel) & 255));
  }
  strip.show();
  delay(50);
  
  currPixel = (currPixel + 1)%256;
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
