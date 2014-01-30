#define colorWipeWait 50

int currPixel = 0;
uint32_t colors[] = {seaHawksGreen, seaHawksBlue};
int colorIndex = 0;


void colorWipeSetup()
{
  currPixel = 0;
  colorIndex = 0;
}

void colorWipeDrawFrame(){
  
  strip.setPixelColor(currPixel, colors[colorIndex]);
  strip.show();
  delay(colorWipeWait);
  
  //if we've lit up all the pixels then change color and start again
  currPixel++;
  if(currPixel >= LIGHT_STRIP_LED_COUNT)
  {
      currPixel = 0;
      colorIndex = (colorIndex + 1) %2;
  }
}


