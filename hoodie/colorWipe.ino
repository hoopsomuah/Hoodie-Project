
int currColorWipePixel = 0;
uint8_t colorWipeWait = 50;

uint32_t colorWipeColors[] = {seaHawksGreen, seaHawksBlue};
int currColorWipeIndex = 0;


void colorWipeSetup()
{
  currColorWipePixel = 0;
  currColorWipeIndex = 0;
}

void colorWipeDrawFrame(){
  
  strip.setPixelColor(currColorWipePixel, colorWipeColors[currColorWipeIndex]);
  strip.show();
  delay(colorWipeWait);
  
  //if we've lit up all the pixels then change color and start again
  currColorWipePixel++;
  if(currColorWipePixel >= LIGHT_STRIP_LED_COUNT)
  {
      currColorWipePixel = 0;
      currColorWipeIndex = (currColorWipeIndex + 1) %2;
  }
}


